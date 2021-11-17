/*
 *  Copyright 2019-2021 Diligent Graphics LLC
 *  Copyright 2015-2019 Egor Yusov
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  In no event and under no legal theory, whether in tort (including negligence),
 *  contract, or otherwise, unless required by applicable law (such as deliberate
 *  and grossly negligent acts) or agreed to in writing, shall any Contributor be
 *  liable for any damages, including any direct, indirect, special, incidental,
 *  or consequential damages of any character arising as a result of this License or
 *  out of the use or inability to use the software (including but not limited to damages
 *  for loss of goodwill, work stoppage, computer failure or malfunction, or any and
 *  all other commercial damages or losses), even if such Contributor has been advised
 *  of the possibility of such damages.
 */

#include "pch.h"

#include "ShaderVkImpl.hpp"

#include <array>
#include <cctype>

#include "RenderDeviceVkImpl.hpp"
#include "DataBlobImpl.hpp"
#include "GLSLUtils.hpp"
#include "DXCompiler.hpp"
#include "ShaderToolsCommon.hpp"

#if !DILIGENT_NO_GLSLANG
#    include "GLSLangUtils.hpp"
#endif

namespace Diligent
{

ShaderVkImpl::ShaderVkImpl(IReferenceCounters*     pRefCounters,
                           RenderDeviceVkImpl*     pRenderDeviceVk,
                           const ShaderCreateInfo& ShaderCI,
                           const CreateInfo&       VkShaderCI,
                           bool                    IsDeviceInternal) :
    // clang-format off
    TShaderBase
    {
        pRefCounters,
        pRenderDeviceVk,
        ShaderCI.Desc,
        VkShaderCI.DeviceInfo,
        VkShaderCI.AdapterInfo,
        IsDeviceInternal
    }
// clang-format on
{
    if (ShaderCI.Source != nullptr || ShaderCI.FilePath != nullptr)
    {
        DEV_CHECK_ERR(ShaderCI.ByteCode == nullptr, "'ByteCode' must be null when shader is created from source code or a file");

        static constexpr char VulkanDefine[] =
            "#ifndef VULKAN\n"
            "#   define VULKAN 1\n"
            "#endif\n"
#if PLATFORM_MACOS || PLATFORM_IOS || PLATFORM_TVOS
            "#ifndef METAL\n"
            "#   define METAL 1\n"
            "#endif\n"
#endif
            ;

        auto ShaderCompiler = ShaderCI.ShaderCompiler;
        if (ShaderCompiler == SHADER_COMPILER_DXC)
        {
            auto* pDXCompiler = VkShaderCI.pDXCompiler;
            if (pDXCompiler == nullptr || !pDXCompiler->IsLoaded())
            {
                LOG_WARNING_MESSAGE("DX Compiler is not loaded. Using default shader compiler");
                ShaderCompiler = SHADER_COMPILER_DEFAULT;
            }
        }

        switch (ShaderCompiler)
        {
            case SHADER_COMPILER_DXC:
            {
                auto* pDXCompiler = VkShaderCI.pDXCompiler;
                VERIFY_EXPR(pDXCompiler != nullptr && pDXCompiler->IsLoaded());
                pDXCompiler->Compile(ShaderCI, ShaderVersion{}, VulkanDefine, nullptr, &m_SPIRV, ShaderCI.ppCompilerOutput);
            }
            break;

            case SHADER_COMPILER_DEFAULT:
            case SHADER_COMPILER_GLSLANG:
            {
#if DILIGENT_NO_GLSLANG
                LOG_ERROR_AND_THROW("Diligent engine was not linked with glslang, use DXC or precompiled SPIRV bytecode.");
#else
                if (ShaderCI.SourceLanguage == SHADER_SOURCE_LANGUAGE_HLSL)
                {
                    m_SPIRV = GLSLangUtils::HLSLtoSPIRV(ShaderCI, VulkanDefine, ShaderCI.ppCompilerOutput);
                }
                else
                {
                    std::string              GLSLSourceString;
                    RefCntAutoPtr<IDataBlob> pSourceFileData;

                    const char*        ShaderSource = nullptr;
                    size_t             SourceLength = ShaderCI.SourceLength;
                    const ShaderMacro* Macros       = nullptr;
                    if (ShaderCI.SourceLanguage == SHADER_SOURCE_LANGUAGE_GLSL_VERBATIM)
                    {
                        // Read the source file directly and use it as is
                        ShaderSource = ReadShaderSourceFile(ShaderCI.Source, ShaderCI.pShaderSourceStreamFactory, ShaderCI.FilePath, pSourceFileData, SourceLength);

                        // Add user macros.
                        // BuildGLSLSourceString adds the macros to the source string, so we don't need to do this for SHADER_SOURCE_LANGUAGE_GLSL
                        Macros = ShaderCI.Macros;
                    }
                    else
                    {
                        // Build the full source code string that will contain GLSL version declaration,
                        // platform definitions, user-provided shader macros, etc.
                        GLSLSourceString = BuildGLSLSourceString(ShaderCI, VkShaderCI.DeviceInfo, VkShaderCI.AdapterInfo, TargetGLSLCompiler::glslang, VulkanDefine);
                        ShaderSource     = GLSLSourceString.c_str();
                        SourceLength     = GLSLSourceString.length();
                    }

                    GLSLangUtils::GLSLtoSPIRVAttribs Attribs;
                    Attribs.ShaderType                 = m_Desc.ShaderType;
                    Attribs.ShaderSource               = ShaderSource;
                    Attribs.SourceCodeLen              = static_cast<int>(SourceLength);
                    Attribs.Version                    = GLSLangUtils::SpirvVersion::Vk100;
                    Attribs.Macros                     = Macros;
                    Attribs.AssignBindings             = true;
                    Attribs.pShaderSourceStreamFactory = ShaderCI.pShaderSourceStreamFactory;
                    Attribs.ppCompilerOutput           = ShaderCI.ppCompilerOutput;

                    if (VkShaderCI.VkVersion >= VK_API_VERSION_1_2)
                        Attribs.Version = GLSLangUtils::SpirvVersion::Vk120;
                    else if (VkShaderCI.VkVersion >= VK_API_VERSION_1_1)
                        Attribs.Version = VkShaderCI.HasSpirv14 ? GLSLangUtils::SpirvVersion::Vk110_Spirv14 : GLSLangUtils::SpirvVersion::Vk110;

                    m_SPIRV = GLSLangUtils::GLSLtoSPIRV(Attribs);
                }
#endif
                break;
            }

            default:
                LOG_ERROR_AND_THROW("Unsupported shader compiler");
        }

        if (m_SPIRV.empty())
        {
            LOG_ERROR_AND_THROW("Failed to compile shader '", ShaderCI.Desc.Name, '\'');
        }
    }
    else if (ShaderCI.ByteCode != nullptr)
    {
        DEV_CHECK_ERR(ShaderCI.ByteCodeSize != 0, "ByteCodeSize must not be 0");
        DEV_CHECK_ERR(ShaderCI.ByteCodeSize % 4 == 0, "Byte code size (", ShaderCI.ByteCodeSize, ") is not multiple of 4");
        m_SPIRV.resize(ShaderCI.ByteCodeSize / 4);
        memcpy(m_SPIRV.data(), ShaderCI.ByteCode, ShaderCI.ByteCodeSize);
    }
    else
    {
        LOG_ERROR_AND_THROW("Shader source must be provided through one of the 'Source', 'FilePath' or 'ByteCode' members");
    }

    // We cannot create shader module here because resource bindings are assigned when
    // pipeline state is created

    // Load shader resources
    auto& Allocator        = GetRawAllocator();
    auto* pRawMem          = ALLOCATE(Allocator, "Allocator for ShaderResources", SPIRVShaderResources, 1);
    auto  LoadShaderInputs = m_Desc.ShaderType == SHADER_TYPE_VERTEX;
    auto* pResources       = new (pRawMem) SPIRVShaderResources //
        {
            Allocator,
            m_SPIRV,
            m_Desc,
            ShaderCI.UseCombinedTextureSamplers ? ShaderCI.CombinedSamplerSuffix : nullptr,
            LoadShaderInputs,
            m_EntryPoint //
        };
    m_pShaderResources.reset(pResources, STDDeleterRawMem<SPIRVShaderResources>(Allocator));

    if (LoadShaderInputs && m_pShaderResources->IsHLSLSource())
    {
        MapHLSLVertexShaderInputs();
    }
}

void ShaderVkImpl::MapHLSLVertexShaderInputs()
{
    for (Uint32 i = 0; i < m_pShaderResources->GetNumShaderStageInputs(); ++i)
    {
        const auto&        Input  = m_pShaderResources->GetShaderStageInputAttribs(i);
        const char*        s      = Input.Semantic;
        static const char* Prefix = "attrib";
        const char*        p      = Prefix;
        while (*s != 0 && *p != 0 && *p == std::tolower(static_cast<unsigned char>(*s)))
        {
            ++p;
            ++s;
        }

        if (*p != 0)
        {
            LOG_ERROR_MESSAGE("Unable to map semantic '", Input.Semantic, "' to input location: semantics must have 'ATTRIBx' format.");
            continue;
        }

        char* EndPtr   = nullptr;
        auto  Location = static_cast<uint32_t>(strtol(s, &EndPtr, 10));
        if (*EndPtr != 0)
        {
            LOG_ERROR_MESSAGE("Unable to map semantic '", Input.Semantic, "' to input location: semantics must have 'ATTRIBx' format.");
            continue;
        }
        m_SPIRV[Input.LocationDecorationOffset] = Location;
    }
}

ShaderVkImpl::~ShaderVkImpl()
{
}

void ShaderVkImpl::GetResourceDesc(Uint32 Index, ShaderResourceDesc& ResourceDesc) const
{
    auto ResCount = GetResourceCount();
    DEV_CHECK_ERR(Index < ResCount, "Resource index (", Index, ") is out of range");
    if (Index < ResCount)
    {
        const auto& SPIRVResource = m_pShaderResources->GetResource(Index);
        ResourceDesc              = SPIRVResource.GetResourceDesc();
    }
}

} // namespace Diligent

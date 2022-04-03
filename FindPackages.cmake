find_package(xxHash CONFIG REQUIRED)
find_package(glslang CONFIG REQUIRED)

# opengl
set(GLEW_USE_STATIC_LIBS ON)
find_package(GLEW REQUIRED)
#vulkan
find_package(volk CONFIG REQUIRED)

find_path(SPIRV_HEADERS_INCLUDE_DIRS "spirv/1.0/GLSL.std.450.h")
add_library(SPIRV-Headers INTERFACE IMPORTED)
target_include_directories(SPIRV-Headers INTERFACE "${SPIRV_HEADERS_INCLUDE_DIRS}")

find_package(SPIRV-Tools CONFIG REQUIRED)
find_package(SPIRV-Tools-opt CONFIG REQUIRED)
find_package(SPIRV-Tools-link CONFIG REQUIRED)
find_package(spirv_cross_core CONFIG REQUIRED)
find_package(spirv_cross_glsl CONFIG REQUIRED)
find_package(spirv_cross_hlsl CONFIG REQUIRED)
set(SPIRV_CROSS_NAMESPACE_OVERRIDE OFF)

find_path(VULKAN_HEADERS_INCLUDE_DIRS "vulkan/vulkan.h")
add_library(Vulkan-Headers INTERFACE IMPORTED)
target_include_directories(Vulkan-Headers INTERFACE "${VULKAN_HEADERS_INCLUDE_DIRS}")
add_library(Vulkan::Headers ALIAS Vulkan-Headers)

# tests
find_package(GTest CONFIG REQUIRED)

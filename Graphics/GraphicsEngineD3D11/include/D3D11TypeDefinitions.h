/*     Copyright 2015-2018 Egor Yusov
 *  
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF ANY PROPRIETARY RIGHTS.
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

#pragma once

/// \file
/// Definitions of D3D11 types

// Filters
#define D3D_FILTER_MIN_MAG_MIP_POINT                D3D11_FILTER_MIN_MAG_MIP_POINT
#define D3D_FILTER_MIN_MAG_POINT_MIP_LINEAR         D3D11_FILTER_MIN_MAG_POINT_MIP_LINEAR
#define D3D_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT   D3D11_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT
#define D3D_FILTER_MIN_POINT_MAG_MIP_LINEAR         D3D11_FILTER_MIN_POINT_MAG_MIP_LINEAR
#define D3D_FILTER_MIN_LINEAR_MAG_MIP_POINT         D3D11_FILTER_MIN_LINEAR_MAG_MIP_POINT
#define D3D_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR  D3D11_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR
#define D3D_FILTER_MIN_MAG_LINEAR_MIP_POINT         D3D11_FILTER_MIN_MAG_LINEAR_MIP_POINT
#define D3D_FILTER_MIN_MAG_MIP_LINEAR               D3D11_FILTER_MIN_MAG_MIP_LINEAR
#define D3D_FILTER_ANISOTROPIC                      D3D11_FILTER_ANISOTROPIC

#define D3D_FILTER_COMPARISON_MIN_MAG_MIP_POINT                 D3D11_FILTER_COMPARISON_MIN_MAG_MIP_POINT
#define D3D_FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR          D3D11_FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR
#define D3D_FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT    D3D11_FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT
#define D3D_FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR          D3D11_FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR
#define D3D_FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT          D3D11_FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT
#define D3D_FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR   D3D11_FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR
#define D3D_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT          D3D11_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT
#define D3D_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR                D3D11_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR
#define D3D_FILTER_COMPARISON_ANISOTROPIC                       D3D11_FILTER_COMPARISON_ANISOTROPIC

// Minimum/maximum filtering is not supported in d3d11
#define D3D_FILTER_MINIMUM_MIN_MAG_MIP_POINT                D3D11_FILTER_MIN_MAG_MIP_POINT
#define D3D_FILTER_MINIMUM_MIN_MAG_POINT_MIP_LINEAR         D3D11_FILTER_MIN_MAG_MIP_POINT
#define D3D_FILTER_MINIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT   D3D11_FILTER_MIN_MAG_MIP_POINT
#define D3D_FILTER_MINIMUM_MIN_POINT_MAG_MIP_LINEAR         D3D11_FILTER_MIN_MAG_MIP_POINT
#define D3D_FILTER_MINIMUM_MIN_LINEAR_MAG_MIP_POINT         D3D11_FILTER_MIN_MAG_MIP_POINT
#define D3D_FILTER_MINIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR  D3D11_FILTER_MIN_MAG_MIP_POINT
#define D3D_FILTER_MINIMUM_MIN_MAG_LINEAR_MIP_POINT         D3D11_FILTER_MIN_MAG_MIP_POINT
#define D3D_FILTER_MINIMUM_MIN_MAG_MIP_LINEAR               D3D11_FILTER_MIN_MAG_MIP_POINT
#define D3D_FILTER_MINIMUM_ANISOTROPIC                      D3D11_FILTER_MIN_MAG_MIP_POINT

#define D3D_FILTER_MAXIMUM_MIN_MAG_MIP_POINT                D3D11_FILTER_MIN_MAG_MIP_POINT
#define D3D_FILTER_MAXIMUM_MIN_MAG_POINT_MIP_LINEAR         D3D11_FILTER_MIN_MAG_MIP_POINT
#define D3D_FILTER_MAXIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT   D3D11_FILTER_MIN_MAG_MIP_POINT
#define D3D_FILTER_MAXIMUM_MIN_POINT_MAG_MIP_LINEAR         D3D11_FILTER_MIN_MAG_MIP_POINT
#define D3D_FILTER_MAXIMUM_MIN_LINEAR_MAG_MIP_POINT         D3D11_FILTER_MIN_MAG_MIP_POINT
#define D3D_FILTER_MAXIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR  D3D11_FILTER_MIN_MAG_MIP_POINT
#define D3D_FILTER_MAXIMUM_MIN_MAG_LINEAR_MIP_POINT         D3D11_FILTER_MIN_MAG_MIP_POINT
#define D3D_FILTER_MAXIMUM_MIN_MAG_MIP_LINEAR               D3D11_FILTER_MIN_MAG_MIP_POINT
#define D3D_FILTER_MAXIMUM_ANISOTROPIC                      D3D11_FILTER_MIN_MAG_MIP_POINT


// Comparison functions
#define D3D_COMPARISON_FUNC_NEVER           D3D11_COMPARISON_NEVER
#define D3D_COMPARISON_FUNC_LESS            D3D11_COMPARISON_LESS
#define D3D_COMPARISON_FUNC_EQUAL           D3D11_COMPARISON_EQUAL
#define D3D_COMPARISON_FUNC_LESS_EQUAL      D3D11_COMPARISON_LESS_EQUAL
#define D3D_COMPARISON_FUNC_GREATER         D3D11_COMPARISON_GREATER
#define D3D_COMPARISON_FUNC_NOT_EQUAL       D3D11_COMPARISON_NOT_EQUAL
#define D3D_COMPARISON_FUNC_GREATER_EQUAL   D3D11_COMPARISON_GREATER_EQUAL
#define D3D_COMPARISON_FUNC_ALWAYS          D3D11_COMPARISON_ALWAYS

// Stencil operations
#define D3D_STENCIL_OP_KEEP     D3D11_STENCIL_OP_KEEP
#define D3D_STENCIL_OP_ZERO     D3D11_STENCIL_OP_ZERO
#define D3D_STENCIL_OP_REPLACE  D3D11_STENCIL_OP_REPLACE
#define D3D_STENCIL_OP_INCR_SAT D3D11_STENCIL_OP_INCR_SAT
#define D3D_STENCIL_OP_DECR_SAT D3D11_STENCIL_OP_DECR_SAT
#define D3D_STENCIL_OP_INVERT   D3D11_STENCIL_OP_INVERT
#define D3D_STENCIL_OP_INCR     D3D11_STENCIL_OP_INCR
#define D3D_STENCIL_OP_DECR     D3D11_STENCIL_OP_DECR

// Depth write masks
#define D3D_DEPTH_WRITE_MASK_ALL    D3D11_DEPTH_WRITE_MASK_ALL
#define D3D_DEPTH_WRITE_MASK_ZERO   D3D11_DEPTH_WRITE_MASK_ZERO

// Cull modes
#define D3D_CULL_MODE_NONE  D3D11_CULL_NONE
#define D3D_CULL_MODE_FRONT D3D11_CULL_FRONT
#define D3D_CULL_MODE_BACK  D3D11_CULL_BACK

// Fill modes
#define D3D_FILL_MODE_WIREFRAME D3D11_FILL_WIREFRAME
#define D3D_FILL_MODE_SOLID     D3D11_FILL_SOLID

// Blend sources
#define D3D_BLEND_ZERO              D3D11_BLEND_ZERO
#define D3D_BLEND_ONE               D3D11_BLEND_ONE
#define D3D_BLEND_SRC_COLOR         D3D11_BLEND_SRC_COLOR
#define D3D_BLEND_INV_SRC_COLOR     D3D11_BLEND_INV_SRC_COLOR
#define D3D_BLEND_SRC_ALPHA         D3D11_BLEND_SRC_ALPHA
#define D3D_BLEND_INV_SRC_ALPHA     D3D11_BLEND_INV_SRC_ALPHA
#define D3D_BLEND_DEST_ALPHA        D3D11_BLEND_DEST_ALPHA
#define D3D_BLEND_INV_DEST_ALPHA    D3D11_BLEND_INV_DEST_ALPHA
#define D3D_BLEND_DEST_COLOR        D3D11_BLEND_DEST_COLOR
#define D3D_BLEND_INV_DEST_COLOR    D3D11_BLEND_INV_DEST_COLOR
#define D3D_BLEND_SRC_ALPHA_SAT     D3D11_BLEND_SRC_ALPHA_SAT
#define D3D_BLEND_BLEND_FACTOR      D3D11_BLEND_BLEND_FACTOR
#define D3D_BLEND_INV_BLEND_FACTOR  D3D11_BLEND_INV_BLEND_FACTOR
#define D3D_BLEND_SRC1_COLOR        D3D11_BLEND_SRC1_COLOR
#define D3D_BLEND_INV_SRC1_COLOR    D3D11_BLEND_INV_SRC1_COLOR
#define D3D_BLEND_SRC1_ALPHA        D3D11_BLEND_SRC1_ALPHA
#define D3D_BLEND_INV_SRC1_ALPHA    D3D11_BLEND_INV_SRC1_ALPHA

// Blend operations
#define D3D_BLEND_OP_ADD          D3D11_BLEND_OP_ADD
#define D3D_BLEND_OP_SUBTRACT     D3D11_BLEND_OP_SUBTRACT
#define D3D_BLEND_OP_REV_SUBTRACT D3D11_BLEND_OP_REV_SUBTRACT
#define D3D_BLEND_OP_MIN          D3D11_BLEND_OP_MIN
#define D3D_BLEND_OP_MAX          D3D11_BLEND_OP_MAX

// Color masks
#define D3D_COLOR_WRITE_ENABLE_RED      D3D11_COLOR_WRITE_ENABLE_RED
#define D3D_COLOR_WRITE_ENABLE_GREEN    D3D11_COLOR_WRITE_ENABLE_GREEN
#define D3D_COLOR_WRITE_ENABLE_BLUE     D3D11_COLOR_WRITE_ENABLE_BLUE
#define D3D_COLOR_WRITE_ENABLE_ALPHA    D3D11_COLOR_WRITE_ENABLE_ALPHA

// Input classification
#define D3D_INPUT_CLASSIFICATION_PER_VERTEX_DATA   D3D11_INPUT_PER_VERTEX_DATA
#define D3D_INPUT_CLASSIFICATION_PER_INSTANCE_DATA D3D11_INPUT_PER_INSTANCE_DATA

// Texture address modes
#define D3D_TEXTURE_ADDRESS_WRAP        D3D11_TEXTURE_ADDRESS_WRAP
#define D3D_TEXTURE_ADDRESS_MIRROR      D3D11_TEXTURE_ADDRESS_MIRROR
#define D3D_TEXTURE_ADDRESS_CLAMP       D3D11_TEXTURE_ADDRESS_CLAMP
#define D3D_TEXTURE_ADDRESS_BORDER      D3D11_TEXTURE_ADDRESS_BORDER
#define D3D_TEXTURE_ADDRESS_MIRROR_ONCE D3D11_TEXTURE_ADDRESS_MIRROR_ONCE


// SRV Dimensions
// d3d11.h aliases D3D11_SRV_DIMENSION as D3D_SRV_DIMENSION, so there is no
// need to redefine this enum

// RTV Dimensions 
#define  D3D_RTV_DIMENSION_UNKNOWN          D3D11_RTV_DIMENSION_UNKNOWN
#define  D3D_RTV_DIMENSION_BUFFER           D3D11_RTV_DIMENSION_BUFFER
#define  D3D_RTV_DIMENSION_TEXTURE1D        D3D11_RTV_DIMENSION_TEXTURE1D
#define  D3D_RTV_DIMENSION_TEXTURE1DARRAY   D3D11_RTV_DIMENSION_TEXTURE1DARRAY
#define  D3D_RTV_DIMENSION_TEXTURE2D        D3D11_RTV_DIMENSION_TEXTURE2D
#define  D3D_RTV_DIMENSION_TEXTURE2DARRAY   D3D11_RTV_DIMENSION_TEXTURE2DARRAY
#define  D3D_RTV_DIMENSION_TEXTURE2DMS      D3D11_RTV_DIMENSION_TEXTURE2DMS
#define  D3D_RTV_DIMENSION_TEXTURE2DMSARRAY D3D11_RTV_DIMENSION_TEXTURE2DMSARRAY
#define  D3D_RTV_DIMENSION_TEXTURE3D        D3D11_RTV_DIMENSION_TEXTURE3D


// DSV Dimensions 
#define D3D_DSV_DIMENSION_UNKNOWN           D3D11_DSV_DIMENSION_UNKNOWN
#define D3D_DSV_DIMENSION_TEXTURE1D         D3D11_DSV_DIMENSION_TEXTURE1D
#define D3D_DSV_DIMENSION_TEXTURE1DARRAY    D3D11_DSV_DIMENSION_TEXTURE1DARRAY
#define D3D_DSV_DIMENSION_TEXTURE2D         D3D11_DSV_DIMENSION_TEXTURE2D
#define D3D_DSV_DIMENSION_TEXTURE2DARRAY    D3D11_DSV_DIMENSION_TEXTURE2DARRAY
#define D3D_DSV_DIMENSION_TEXTURE2DMS       D3D11_DSV_DIMENSION_TEXTURE2DMS
#define D3D_DSV_DIMENSION_TEXTURE2DMSARRAY  D3D11_DSV_DIMENSION_TEXTURE2DMSARRAY

// UAV Dimensions
#define D3D_UAV_DIMENSION_UNKNOWN           D3D11_UAV_DIMENSION_UNKNOWN
#define D3D_UAV_DIMENSION_BUFFER            D3D11_UAV_DIMENSION_BUFFER
#define D3D_UAV_DIMENSION_TEXTURE1D         D3D11_UAV_DIMENSION_TEXTURE1D
#define D3D_UAV_DIMENSION_TEXTURE1DARRAY    D3D11_UAV_DIMENSION_TEXTURE1DARRAY
#define D3D_UAV_DIMENSION_TEXTURE2D         D3D11_UAV_DIMENSION_TEXTURE2D
#define D3D_UAV_DIMENSION_TEXTURE2DARRAY    D3D11_UAV_DIMENSION_TEXTURE2DARRAY
#define D3D_UAV_DIMENSION_TEXTURE3D         D3D11_UAV_DIMENSION_TEXTURE3D

// Buffer flags
#define D3D_BUFFER_UAV_FLAG_RAW             D3D11_BUFFER_UAV_FLAG_RAW
#define D3D_BUFFER_UAV_FLAG_NONE            0
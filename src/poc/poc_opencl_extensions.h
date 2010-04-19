/*
 * Copyright (c) 2009-2010, Bjoern Knafla
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this 
 *   list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice, 
 *   this list of conditions and the following disclaimer in the documentation 
 *   and/or other materials provided with the distribution.
 * - Neither the name of the Bjoern Knafla nor the names of its contributors may 
 *   be used to endorse or promote products derived from this software without 
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 *
 * POC users can define @c POC_OPENCL_EXTENSION_ prefixed macros to try to 
 * enable or disable certain OpenCL extensions. Enabling an extension activates 
 * the associated extension pragma and defines an associated 
 * @c POC_OPENCL_EXTENSION_ENABLED_ prefixed macro.
 *
 * An extension can only be enabled if it is supported by the OpenCL compiler
 * and device.
 *
 * Other macros mirror mode settings of OpenCL. e.g. 
 * @c POC_OPENCL_SET_FP_CONTRACT_ON, @c POC_OPENCL_SET_FP_CONTRACT_OFF, 
 * @c POC_OPENCL_SET_FP_CONTRACT_DEFAULT, or 
 * @c POC_OPENCL_SET_SELECT_ROUNDING_MODE_NEAREST_EVEN, etc.
 *
 * @todo TODO: Add further OpenCL extensions, add _def.h and @c _undef.h
 *       headers, include headers into poc_primary_types headers.
 * @todo TODO: Document header.
 */

/**
 * @def POC_OPENCL_EXTENSION_ENABLED_KHR_FP64
 *
 */


#ifndef POC_poc_opencl_extensions_H
#define POC_poc_opencl_extensions_H

#include "poc_lang.h"

#include "poc_opencl_extensions_def.h"

/* Disable macro undefines via including poc_opencl_extensions_undef.h and 
 * prevent re-defines from accidential includes of poc_opencl_extensions_def.h .
 */
#define POC_OPENCL_EXTENSIONS_HEADER_DISABLE_DEF_UNDEF

#endif /* POC_poc_opencl_extensions_H */

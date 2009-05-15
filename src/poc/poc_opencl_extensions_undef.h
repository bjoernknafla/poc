/*
 * Copyright (c) 2009, Bjoern Knafla
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
 * Undefines POC OpenCL extension macros potentially set by 
 * poc_opencl_extensions_def.h , see poc_opencl_extensions.h and 
 * poc_opencl_extensions_def.h for more details.
 *
 * @attention Be careful with this undefine header - typicalle the try disable
 *            macros described in poc_opencl_extensions.h disable an enabled
 *            extension and undefine the @c POC_OPENCL_EXTENSION_ENABLED_ macro 
 *            associated with it. Just undefining these macros doesn't disable
 *            the associated extension and makes it impossible to test later on
 *            if it is active or not.
 *
 * @attention This header doesn't have header guards to enable multiple 
 *            inclusion.
 */



/* Only allow undefines of POC OpenCL extensions if poc_opencl_extensions.h 
 * hasn't been included in this compilation unit.
 */
#if !defined(POC_OPENCL_EXTENSIONS_HEADER_DISABLE_DEF_UNDEF)



#undef POC_OPENCL_EXTENSION_ENABLED_KHR_FP64
#undef POC_OPENCL_EXTENSION_ENABLED_KHR_SELECT_FPROUNDING_MODE
#undef POC_OPENCL_EXTENSION_ENABLED_KHR_GLOBAL_INT32_BASE_ATOMICS
#undef POC_OPENCL_EXTENSION_ENABLED_KHR_GLOBAL_INT32_EXTENDED_ATOMICS
#undef POC_OPENCL_EXTENSION_ENABLED_KHR_LOCAL_INT32_BASE_ATOMICS
#undef POC_OPENCL_EXTENSION_ENABLED_KHR_LOCAL_INT32_EXTENDED_ATOMICS
#undef POC_OPENCL_EXTENSION_ENABLED_KHR_INT64_BASE_ATOMICS
#undef POC_OPENCL_EXTENSION_ENABLED_KHR_INT64_EXTENDED_ATOMICS
#undef POC_OPENCL_EXTENSION_ENABLED_KHR_3D_IMAGE_WRITES
#undef POC_OPENCL_EXTENSION_ENABLED_KHR_BYTE_ADDRESSABLE_STORE
#undef POC_OPENCL_EXTENSION_ENABLED_KHR_FP16

#endif /* POC_OPENCL_EXTENSIONS_HEADER_DISABLE_DEF_UNDEF */

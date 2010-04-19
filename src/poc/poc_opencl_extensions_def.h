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
 * See poc_opencl_extensions.h for details.
 *
 * @attention This header doesn't have header guards to allow successive 
 *            inclusion of it and its sibling poc_opencl_extensions_undef.h . If 
 *            header guards are wanted or needed use poc.h or 
 *            poc_opencl_extensions.h instead.
 *
 * @todo TODO: Add diagnose to poc_diagnose.c .
 */




/* Only allow definition of POC OpenCL extensions if poc_opencl_extensions.h 
 * hasn't been included in this compilation unit.
 */
#if !defined(POC_OPENCL_EXTENSIONS_HEADER_DISABLE_DEF_UNDEF)

#include "poc_lang_def.h"


#if defined(POC_LANG_OPENCL)



#if defined(POC_OPENCL_SET_FP_CONTRACT_ON)
#   pragma OPENCL FP_CONTRACT ON
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(POC_OPENCL_SET_FP_CONTRACT_OFF)
#   pragma OPENCL FP_CONTRACT OFF
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif 

#if defined(POC_OPENCL_SET_FP_CONTRACT_DEFAUL)
#   pragma OPENCL FP_CONTRACT DEFAUT
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif



#if defined(cl_khr_fp64) && defined(POC_OPENCL_EXTENSION_TRY_ENABLE_KHR_FP64)
#   pragma OPENCL EXTENSION cl_khr_fp64 : enable
#   define POC_OPENCL_EXTENSION_ENABLED_KHR_FP64 1
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(cl_khr_fp64) && defined(POC_OPENCL_EXTENSION_TRY_DISABLE_KHR_FP64)
#   pragma OPENCL EXTENSION cl_khr_fp64 : disable
#   undef POC_OPENCL_EXTENSION_ENABLED_KHR_FP64
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif



#if defined(cl_khr_select_fprounding_mode) && defined(POC_OPENCL_EXTENSION_TRY_ENABLE_KHR_SELECT_FPROUNDING_MODE)
#   pragma OPENCL EXTENSION cl_khr_select_fprounding_mode : enable
#   define POC_OPENCL_EXTENSION_ENABLED_KHR_SELECT_FPROUNDING_MODE 1
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(cl_khr_select_fprounding_mode) && defined(POC_OPENCL_EXTENSION_TRY_DISABLE_KHR_SELECT_FPROUNDING_MODE)
#   pragma OPENCL EXTENSION cl_khr_select_fprounding_mode : disable
#   undef POC_OPENCL_EXTENSION_ENABLED_KHR_SELECT_FPROUNDING_MODE
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(POC_OPENCL_EXTENSION_ENABLED_KHR_SELECT_FPROUNDING_MODE) && defined(POC_OPENCL_SET_SELECT_ROUNDING_MODE_NEAREST_EVEN)
#   pragma OPENCL SELECT_ROUNDING_MODE rte
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(POC_OPENCL_EXTENSION_ENABLED_KHR_SELECT_FPROUNDING_MODE) && defined(POC_OPENCL_SET_SELECT_ROUNDING_MODE_ZERO)
#   pragma OPENCL SELECT_ROUNDING_MODE rtz
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(POC_OPENCL_EXTENSION_ENABLED_KHR_SELECT_FPROUNDING_MODE) && defined(POC_OPENCL_SET_SELECT_ROUNDING_MODE_POSITIVE_INFINITY)
#   pragma OPENCL SELECT_ROUNDING_MODE rtp
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(POC_OPENCL_EXTENSION_ENABLED_KHR_SELECT_FPROUNDING_MODE) && defined(POC_OPENCL_SET_SELECT_ROUNDING_MODE_NEGATIVE_INFINITY)
#   pragma OPENCL SELECT_ROUNDING_MODE rtn
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif






#if defined(cl_khr_global_int32_base_atomics) && defined(POC_OPENCL_EXTENSION_TRY_ENABLE_KHR_GLOBAL_INT32_BASE_ATOMICS)
#   pragma OPENCL EXTENSION cl_khr_global_int32_base_atomics : enable
#   define POC_OPENCL_EXTENSION_ENABLED_KHR_GLOBAL_INT32_BASE_ATOMICS 1
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(cl_khr_global_int32_base_atomics) && defined(POC_OPENCL_EXTENSION_TRY_DISABLE_KHR_GLOBAL_INT32_BASE_ATOMICS)
#   pragma OPENCL EXTENSION cl_khr_global_int32_base_atomics : disable
#   undef POC_OPENCL_EXTENSION_ENABLED_KHR_GLOBAL_INT32_BASE_ATOMICS
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif



#if defined(cl_khr_global_int32_extended_atomics) && defined(POC_OPENCL_EXTENSION_TRY_ENABLE_KHR_GLOBAL_INT32_EXTENDED_ATOMICS)
#   pragma OPENCL EXTENSION cl_khr_global_int32_extended_atomics : enable
#   define POC_OPENCL_EXTENSION_ENABLED_KHR_GLOBAL_INT32_EXTENDED_ATOMICS 1
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(cl_khr_global_int32_extended_atomics) && defined(POC_OPENCL_EXTENSION_TRY_DISABLE_KHR_GLOBAL_INT32_EXTENDED_ATOMICS)
#   pragma OPENCL EXTENSION cl_khr_global_int32_extended_atomics : disable
#   undef POC_OPENCL_EXTENSION_ENABLED_KHR_GLOBAL_INT32_EXTENDED_ATOMICS
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif







#if defined(cl_khr_local_int32_base_atomics) && defined(POC_OPENCL_EXTENSION_TRY_ENABLE_KHR_LOCAL_INT32_BASE_ATOMICS)
#   pragma OPENCL EXTENSION cl_khr_local_int32_base_atomics : enable
#   define POC_OPENCL_EXTENSION_ENABLED_KHR_LOCAL_INT32_BASE_ATOMICS 1
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(cl_khr_local_int32_base_atomics) && defined(POC_OPENCL_EXTENSION_TRY_DISABLE_KHR_LOCAL_INT32_BASE_ATOMICS)
#   pragma OPENCL EXTENSION cl_khr_local_int32_base_atomics : disable
#   undef POC_OPENCL_EXTENSION_ENABLED_KHR_LOCAL_INT32_BASE_ATOMICS
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif



#if defined(cl_khr_local_int32_extended_atomics) && defined(POC_OPENCL_EXTENSION_TRY_ENABLE_KHR_LOCAL_INT32_EXTENDED_ATOMICS)
#   pragma OPENCL EXTENSION cl_khr_local_int32_extended_atomics : enable
#   define POC_OPENCL_EXTENSION_ENABLED_KHR_LOCAL_INT32_EXTENDED_ATOMICS 1
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(cl_khr_local_int32_extended_atomics) && defined(POC_OPENCL_EXTENSION_TRY_DISABLE_KHR_LOCAL_INT32_EXTENDED_ATOMICS)
#   pragma OPENCL EXTENSION cl_khr_local_int32_extended_atomics : disable
#   undef POC_OPENCL_EXTENSION_ENABLED_KHR_LOCAL_INT32_EXTENDED_ATOMICS
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif





#if defined(cl_khr_int64_base_atomics) && defined(POC_OPENCL_EXTENSION_TRY_ENABLE_KHR_INT64_BASE_ATOMICS)
#   pragma OPENCL EXTENSION cl_khr_int64_base_atomics : enable
#   define POC_OPENCL_EXTENSION_ENABLED_KHR_INT64_BASE_ATOMICS 1
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(cl_khr_int64_base_atomics) && defined(POC_OPENCL_EXTENSION_TRY_DISABLE_KHR_INT64_BASE_ATOMICS)
#   pragma OPENCL EXTENSION cl_khr_int64_base_atomics : disable
#   undef POC_OPENCL_EXTENSION_ENABLED_KHR_INT64_BASE_ATOMICS
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif



#if defined(cl_khr_int64_extended_atomics) && defined(POC_OPENCL_EXTENSION_TRY_ENABLE_KHR_INT64_EXTENDED_ATOMICS)
#   pragma OPENCL EXTENSION cl_khr_int64_extended_atomics : enable
#   define POC_OPENCL_EXTENSION_ENABLED_KHR_INT64_EXTENDED_ATOMICS 1
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(cl_khr_int64_extended_atomics) && defined(POC_OPENCL_EXTENSION_TRY_DISABLE_KHR_INT64_EXTENDED_ATOMICS)
#   pragma OPENCL EXTENSION cl_khr_int64_extended_atomics : disable
#   undef POC_OPENCL_EXTENSION_ENABLED_KHR_INT64_EXTENDED_ATOMICS
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif




#if defined(cl_khr_3d_image_writes) && defined(POC_OPENCL_EXTENSION_TRY_ENABLE_KHR_3D_IMAGE_WRITES)
#   pragma OPENCL EXTENSION cl_khr_3d_image_writes : enable
#   define POC_OPENCL_EXTENSION_ENABLED_KHR_3D_IMAGE_WRITES 1
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(cl_khr_3d_image_writes) && defined(POC_OPENCL_EXTENSION_TRY_DISABLE_KHR_3D_IMAGE_WRITES)
#   pragma OPENCL EXTENSION cl_khr_3d_image_writes : disable
#   undef POC_OPENCL_EXTENSION_ENABLED_KHR_3D_IMAGE_WRITES
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif



#if defined(cl_khr_byte_addressable_store) && defined(POC_OPENCL_EXTENSION_TRY_ENABLE_KHR_BYTE_ADDRESSABLE_STORE)
#   pragma OPENCL EXTENSION cl_khr_byte_addressable_store : enable
#   define POC_OPENCL_EXTENSION_ENABLED_KHR_BYTE_ADDRESSABLE_STORE 1
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(cl_khr_byte_addressable_store) && defined(POC_OPENCL_EXTENSION_TRY_DISABLE_KHR_BYTE_ADDRESSABLE_STORE)
#   pragma OPENCL EXTENSION cl_khr_byte_addressable_store : disable
#   undef POC_OPENCL_EXTENSION_ENABLED_KHR_BYTE_ADDRESSABLE_STORE
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif




#if defined(cl_khr_fp16) && defined(POC_OPENCL_EXTENSION_TRY_ENABLE_KHR_FP16)
#   pragma OPENCL EXTENSION cl_khr_fp16 : enable
#   define POC_OPENCL_EXTENSION_ENABLED_KHR_FP16 1
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(cl_khr_fp16) && defined(POC_OPENCL_EXTENSION_TRY_DISABLE_KHR_FP16)
#   pragma OPENCL EXTENSION cl_khr_fp16 : disable
#   undef POC_OPENCL_EXTENSION_ENABLED_KHR_FP16
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif



/*******************************************************************************
 * Error check
 ******************************************************************************/


/*
 * Check that not two macros that try to enable and disable an extension are
 * active at the same time.
 */
#if defined(POC_OPENCL_EXTENSION_TRY_ENABLE_KHR_FP64) && defined(POC_OPENCL_EXTENSION_TRY_DISABLE_KHR_FP64)
#   error Try enable and try disable macros mustn't be active together.
#endif

#if defined(POC_OPENCL_EXTENSION_TRY_ENABLE_KHR_SELECT_FPROUNDING_MODE) && defined(POC_OPENCL_EXTENSION_TRY_DISABLE_KHR_SELECT_FPROUNDING_MODE)
#   error Try enable and try disable macros mustn't be active together.
#endif

#if defined(POC_OPENCL_EXTENSION_TRY_ENABLE_KHR_GLOBAL_INT32_BASE_ATOMICS) && defined(POC_OPENCL_EXTENSION_TRY_DISABLE_KHR_GLOBAL_INT32_BASE_ATOMICS)
#   error Try enable and try disable macros mustn't be active together.
#endif

#if defined(POC_OPENCL_EXTENSION_TRY_ENABLE_KHR_GLOBAL_INT32_EXTENDED_ATOMICS) && defined(POC_OPENCL_EXTENSION_TRY_DISABLE_KHR_GLOBAL_INT32_EXTENDED_ATOMICS)
#   error Try enable and try disable macros mustn't be active together.
#endif

#if defined(POC_OPENCL_EXTENSION_TRY_ENABLE_KHR_LOCAL_INT32_BASE_ATOMICS) && defined(POC_OPENCL_EXTENSION_TRY_DISABLE_KHR_LOCAL_INT32_BASE_ATOMICS)
#   error Try enable and try disable macros mustn't be active together.
#endif

#if defined(POC_OPENCL_EXTENSION_TRY_ENABLE_KHR_LOCAL_INT32_EXTENDED_ATOMICS) && defined(POC_OPENCL_EXTENSION_TRY_DISABLE_KHR_LOCAL_INT32_EXTENDED_ATOMICS)
#   error Try enable and try disable macros mustn't be active together.
#endif

#if defined(POC_OPENCL_EXTENSION_TRY_ENABLE_KHR_INT64_BASE_ATOMICS) && defined(POC_OPENCL_EXTENSION_TRY_DISABLE_KHR_INT64_BASE_ATOMICS)
#   error Try enable and try disable macros mustn't be active together.
#endif

#if defined(POC_OPENCL_EXTENSION_TRY_ENABLE_KHR_INT64_EXTENDED_ATOMICS) && defined(POC_OPENCL_EXTENSION_TRY_DISABLE_KHR_INT64_EXTENDED_ATOMICS)
#   error Try enable and try disable macros mustn't be active together.
#endif

#if defined(POC_OPENCL_EXTENSION_TRY_ENABLE_KHR_3D_IMAGE_WRITES) && defined(POC_OPENCL_EXTENSION_TRY_DISABLE_KHR_3D_IMAGE_WRITES)
#   error Try enable and try disable macros mustn't be active together.
#endif

#if defined(POC_OPENCL_EXTENSION_TRY_ENABLE_KHR_BYTE_ADDRESSABLE_STORE) && defined(POC_OPENCL_EXTENSION_TRY_DISABLE_KHR_BYTE_ADDRESSABLE_STORE)
#   error Try enable and try disable macros mustn't be active together.
#endif

#if defined(POC_OPENCL_EXTENSION_TRY_ENABLE_KHR_FP16) && defined(POC_OPENCL_EXTENSION_TRY_DISABLE_KHR_FP16)
#   error Try enable and try disable macros mustn't be active together.
#endif



/*
 * Check that only one rounding mode is active at one time.
 */
#if defined(POC_OPENCL_SET_SELECT_ROUNDING_MODE_NEAREST_EVEN) && ( \
defined(POC_OPENCL_SET_SELECT_ROUNDING_MODE_ZERO) || \
defined(POC_OPENCL_SET_SELECT_ROUNDING_MODE_POSITIVE_INFINITY) || \
defined(POC_OPENCL_SET_SELECT_ROUNDING_MODE_NEGATIVE_INFINITY)  )
#   error Try enable and try disable macros mustn't be active together.
#endif

#if defined(POC_OPENCL_SET_SELECT_ROUNDING_MODE_ZERO) && ( \
defined(POC_OPENCL_SET_SELECT_ROUNDING_MODE_NEAREST_EVEN) || \
defined(POC_OPENCL_SET_SELECT_ROUNDING_MODE_POSITIVE_INFINITY) || \
defined(POC_OPENCL_SET_SELECT_ROUNDING_MODE_NEGATIVE_INFINITY)  )
#   error Try enable and try disable macros mustn't be active together.
#endif

#if defined(POC_OPENCL_SET_SELECT_ROUNDING_MODE_POSITIVE_INFINITY) && ( \
defined(POC_OPENCL_SET_SELECT_ROUNDING_MODE_ZERO) || \
defined(POC_OPENCL_SET_SELECT_ROUNDING_MODE_NEAREST_EVEN) || \
defined(POC_OPENCL_SET_SELECT_ROUNDING_MODE_NEGATIVE_INFINITY)  )
#   error Try enable and try disable macros mustn't be active together.
#endif

#if defined(POC_OPENCL_SET_SELECT_ROUNDING_MODE_NEGATIVE_INFINITY) && ( \
defined(POC_OPENCL_SET_SELECT_ROUNDING_MODE_ZERO) || \
defined(POC_OPENCL_SET_SELECT_ROUNDING_MODE_POSITIVE_INFINITY) || \
defined(POC_OPENCL_SET_SELECT_ROUNDING_MODE_NEAREST_EVEN)  )
#   error Try enable and try disable macros mustn't be active together.
#endif




#endif /* defined(POC_LANG_OPENCL) */




#endif /* !defined(POC_OPENCL_EXTENSIONS_HEADER_DISABLE_DEF_UNDEF) */

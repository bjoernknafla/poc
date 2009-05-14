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
 * See poc_data_model.h for details.
 *
 * @attention This header doesn't have header guards to allow successive inclusion of it and its sibling 
 *            poc_data_model_undef.h . If header guards are wanted or needed use 
 *            poc.h or poc_data_model.h instead.
 *
 * @todo TODO: Detect data model based on OS and compiler.
 */

/* Only allow definition of POC data model macros if poc_data_model.h hasn't been included 
 * in this compilation unit.
 *
 * When compiling with C++ include the header 
 * poc_data_models_cpp_compile_time_checks.h for compile-time checks if the data
 * model corresponds with the primary type bit-sizes.
 */
#if !defined(POC_DATA_MODEL_HEADER_DISABLE_DEF_UNDEF)




/* Include POC_OS preprocessor symbols
 */
#include "poc_os_def.h"

/* Include POC_ARCH preprocessor symbols
 */
#include "poc_arch_def.h"

/* Include POC_LANG preprocessor symbols
 */
#include "poc_lang_def.h"

/***************************************************************************//**
 * @name Predefined data model ids for 32 and 64 bit environments.
 ******************************************************************************/
/*@{*/
#define POC_DATA_MODEL_UNKNOWN_ID 0
#define POC_DATA_MODEL_IP32_ID (1)
#define POC_DATA_MODEL_LP32_ID (1 << 1) /* No detection implemented. */
#define POC_DATA_MODEL_ILP32_ID (1 << 2)
#define POC_DATA_MODEL_LP64_ID (1 << 3)
#define POC_DATA_MODEL_LLP64_ID (1 << 4)
#define POC_DATA_MODEL_ILP64_ID (1 << 5) /* No detection implemented. */
#define POC_DATA_MODEL_SILP64_ID (1 << 6) /* No detection implemented. */
/*@}*/

/***************************************************************************//**
 * @name Predefined data model strings for 32 and 64 bit environments.
 *
 * See:
 * - http://www.ddj.com/hpc-high-performance-computing/184401972
 * - http://en.wikipedia.org/wiki/64-bit
 * - http://en.wikipedia.org/wiki/32-bit
 * - http://archive.opengroup.org/public/tech/aspen/lp64_wp.htm
 *
 * Data models:
 * - IP32: int type and pointer types are 32bit, long might be 64bit.
 * - LP32: int type is 16 bit long and pointer types are 32 bit. Unsupported.
 * - ILP32: int, long, and pointer data types are 32 bit.
 * - LP64: long and pointer types are 64bit, the int type is 32 bit.
 * - LLP64: pointer types are 64bit, the int type is 32 bit, long long is a 
 *          64 bit type.
 * - ILP64: int, long, and pointer types are 64 bit. Unsupported.
 * - SILP64: short, int, long, and pointer types are 64 bit. Unsupported.
 ******************************************************************************/
/*@{*/
#define POC_DATA_MODEL_UNKNOWN_STRING "Unknown data model"
#define POC_DATA_MODEL_IP32_STRING "IP32"
#define POC_DATA_MODEL_LP32_STRING "LP32" /* No detection implemented. */
#define POC_DATA_MODEL_ILP32_STRING "ILP32"
#define POC_DATA_MODEL_LP64_STRING "LP64"
#define POC_DATA_MODEL_LLP64_STRING "LLP64"
#define POC_DATA_MODEL_ILP64_STRING "ILP64" /* No detection implemented. */
#define POC_DATA_MODEL_SILP64_STRING "SILP64" /* No detection implemented. */
/*@}*/



#if !defined(POC_DATA_MODEL_DISABLE_AUTODETECT) && !defined(POC_DISABLE_AUTODETECT)


/*******************************************************************************
 * Detect data model.
 *
 * To detect the data model used by the target platform first the target 
 * operating system and then the architecture are analyzed.
 ******************************************************************************/

/**
 * @todo TODO: Implement data model detection for Linux, Unix, etc.
 */

/* 
 * 32bit Mac OS X uses the ILP32 data model, 64bit Mac OS X uses the LP64 data model.
 */
#if defined(POC_OS_MACOSX)
#   if defined(_LP64) || defined(__LP64__) 
#       define POC_DATA_MODEL_LP64 POC_DATA_MODEL_LP64_ID
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   else
#       if defined(POC_ARCH_X86_64)
#           error On 64bit Mac OS X the _LP64 or __LP64__ symbol should be set.
#       endif
#       define POC_DATA_MODEL_ILP32 POC_DATA_MODEL_ILP32_ID
#   endif
#endif


/* 
 * 32bit Linux uses the ILP32 data model, 64bit Linux uses the LP64 data model.
 */
#if defined(POC_OS_LINUX)
#   if defined(_LP64) || defined(__LP64__) || defined(__lp64)
#       define POC_DATA_MODEL_LP64 POC_DATA_MODEL_LP64_ID
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   else
#       if defined(POC_ARCH_X86_64)
#           error On 64bit Linux the _LP64 or __LP64__ symbol should be set.
#       endif
#       define POC_DATA_MODEL_ILP32 POC_DATA_MODEL_ILP32_ID
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif


/* 
 * Win32 uses the ILP32 data model
 */
#if defined(POC_OS_WIN32)
#   define POC_DATA_MODEL_ILP32 POC_DATA_MODEL_ILP32_ID
#endif


/* 
 * Win64 uses the LLP64 data model
 */
#if defined(POC_OS_WIN64)
#   define POC_DATA_MODEL_LLP64 POC_DATA_MODEL_LLP64_ID
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

/*
 * OpenCL uses the IP32 data model when compiling for 32bit devices or the
 * LP64 data model when compiling for 64bit devices.
 */
#if defined(POC_LANG_OPENCL)
#   if defined(CL_DEVICE_ADDRESS_SPACE) && (32 == CL_DEVICE_ADDRESS_SPACE)
#       define POC_DATA_MODEL_IP32 POC_DATA_MODEL_IP32_ID
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   elif defined(CL_DEVICE_ADDRESS_SPACE) && (64 == CL_DEVICE_ADDRESS_SPACE)
#       define POC_DATA_MODEL_LP64 POC_DATA_MODEL_LP64_ID
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   else
#       error Can't determine OpenCL device address space via CL_DEVICE_ADDRESS_SPACE.
#   endif
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif



/*
 * Cell BE PPU binaries use the ILP32 data model when compiled for 32bit, or
 * may use the LP64 data model when compiled for 64bits.
 */
#if defined(POC_ARCH_CELL_PPU) && !(defined(POC_DATA_MODEL_LP64) || defined(POC_DATA_MODEL_ILP32))
#   if defined(__LP64__) || defined(_LP64)
#       define POC_DATA_MODEL_LP64 POC_DATA_MODEL_LP64_ID
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   elif defined(__ILP32__) || defined(_ILP32)
#       define POC_DATA_MODEL_ILP32 POC_DATA_MODEL_ILP32_ID
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   else
#       /* Assuming ILP32 data model if @c __LP64__ isn't defined */
#       define POC_DATA_MODEL_ILP32 POC_DATA_MODEL_ILP32_ID
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

/*
 * Cell BE SPU binaries always uses an ILP32 ABI. See http://www-01.ibm.com/chips/techlib/techlib.nsf/techdocs/1741C509C5F64B3300257460006FD68D/$file/CellBE_PXCell_Handbook_v1.11_12May08_pub.pdf .
 */
#if defined(POC_ARCH_CELL_SPU)
#   define POC_DATA_MODEL POC_DATA_MODEL_ILP32_ID
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif


/*******************************************************************************
 * Detect @c POC_DATA_MODEL_ID and @c POC_DATA_MODEL_STRING
 ******************************************************************************/

#if defined(POC_DATA_MODEL_IP32)
#   define POC_DATA_MODEL POC_DATA_MODEL_IP32_ID
#   define POC_DATA_MODEL_STRING POC_DATA_MODEL_IP32_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(POC_DATA_MODEL_ILP32)
#   define POC_DATA_MODEL POC_DATA_MODEL_ILP32_ID
#   define POC_DATA_MODEL_STRING POC_DATA_MODEL_ILP32_STRING
#endif

#if defined(POC_DATA_MODEL_LP64)
#   define POC_DATA_MODEL POC_DATA_MODEL_LP64_ID
#   define POC_DATA_MODEL_STRING POC_DATA_MODEL_LP64_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(POC_DATA_MODEL_LLP64)
#   define POC_DATA_MODEL POC_DATA_MODEL_LLP64_ID
#   define POC_DATA_MODEL_STRING POC_DATA_MODEL_LLP64_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif



#endif /* !defined(POC_DATA_MODEL_DISABLE_AUTODETECT) && !defined(POC_DISABLE_AUTODETECT) */


/* 
 * No known data model detected.
 */
#if !defined(POC_DATA_MODEL)
#   define POC_DATA_MODEL_UNKNOWN POC_DATA_MODEL_UNKNOWN_ID
#   define POC_DATA_MODEL POC_DATA_MODEL_UNKNOWN_ID
#   error Unknown data model.
#endif

#if !defined(POC_DATA_MODEL_STRING)
#   define POC_DATA_MODEL_STRING POC_DATA_MODEL_UNKNOWN_STRING
#   error Unknown data model string.
#endif



/*******************************************************************************
 * Correctnes checks and tests
 ******************************************************************************/

/* Exactly one data model must have been chosen - xor tests to find possible error.
 */
#if defined(POC_DATA_MODEL_LP32) \
&& (defined(POC_DATA_MODEL_ILP32) \
|| defined(POC_DATA_MODEL_LP64) \
|| defined(POC_DATA_MODEL_LLP64) \
|| defined(POC_DATA_MODEL_ILP64) \
|| defined(POC_DATA_MODEL_SILP64) \
|| defined(POC_DATA_MODEL_IP32) )
#   error Exactly one data model must be selected.
#elif defined(POC_DATA_MODEL_ILP32) \
&& (defined(POC_DATA_MODEL_LP32) \
|| defined(POC_DATA_MODEL_LP64) \
|| defined(POC_DATA_MODEL_LLP64) \
|| defined(POC_DATA_MODEL_ILP64) \
|| defined(POC_DATA_MODEL_SILP64) \
|| defined(POC_DATA_MODEL_IP32) )
#   error Exactly one data model must be selected.
#elif defined(POC_DATA_MODEL_LP64) \
&& (defined(POC_DATA_MODEL_LP32) \
|| defined(POC_DATA_MODEL_ILP32) \
|| defined(POC_DATA_MODEL_LLP64) \
|| defined(POC_DATA_MODEL_ILP64) \
|| defined(POC_DATA_MODEL_SILP64) \
|| defined(POC_DATA_MODEL_IP32) )
#   error Exactly one data model must be selected.
#elif defined(POC_DATA_MODEL_LLP64) \
&& (defined(POC_DATA_MODEL_LP32) \
|| defined(POC_DATA_MODEL_ILP32) \
|| defined(POC_DATA_MODEL_LP64) \
|| defined(POC_DATA_MODEL_ILP64) \
|| defined(POC_DATA_MODEL_SILP64) \
|| defined(POC_DATA_MODEL_IP32) )
#   error Exactly one data model must be selected.
#elif defined(POC_DATA_MODEL_ILP64) \
&& (defined(POC_DATA_MODEL_LP32) \
|| defined(POC_DATA_MODEL_ILP32) \
|| defined(POC_DATA_MODEL_LP64) \
|| defined(POC_DATA_MODEL_LLP64) \
|| defined(POC_DATA_MODEL_SILP64) \
|| defined(POC_DATA_MODEL_IP32) )
#   error Exactly one data model must be selected.
#elif defined(POC_DATA_MODEL_SILP64) \
&& (defined(POC_DATA_MODEL_LP32) \
|| defined(POC_DATA_MODEL_ILP32) \
|| defined(POC_DATA_MODEL_LP64) \
|| defined(POC_DATA_MODEL_LLP64) \
|| defined(POC_DATA_MODEL_ILP64) \
|| defined(POC_DATA_MODEL_IP32) )
#   error Exactly one data model must be selected.
#elif defined(POC_DATA_MODEL_IP32) \
&& (defined(POC_DATA_MODEL_LP32) \
|| defined(POC_DATA_MODEL_ILP32) \
|| defined(POC_DATA_MODEL_LP64) \
|| defined(POC_DATA_MODEL_LLP64) \
|| defined(POC_DATA_MODEL_ILP64) \
|| defined(POC_DATA_MODEL_SILP64) )
#   error Exactly one data model must be selected.
#endif


#endif /* !defined(POC_DATA_MODEL_HEADER_DISABLE_DEF_UNDEF) */

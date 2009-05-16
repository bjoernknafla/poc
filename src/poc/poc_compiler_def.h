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
 * Collection of @c POC_COMPILER_ prefixed preprocessor macros to identify the compiler compiling the code.
 *
 * See poc_arch.h for details.
 *
 * @attention This header doesn't have header guards to allow successive inclusion of it and its sibling 
 *            poc_compiler_undef.h . If header guards are wanted or needed use poc.h or 
 *            poc_compiler.h instead.
 */

/* Only allow definition of POC compiler macros if poc_compiler.h hasn't been included 
 * in this compilation unit.
 */
#if !defined(POC_COMPILER_HEADER_DISABLE_DEF_UNDEF)


/***************************************************************************//**
 * @name Predefined compiler ids.
 *
 * @todo TODO: Move all ids of all POC headers to the value @c 1 to allow binary-logic-or-tests for it.
 * @todo TODO: Add OpenCL compiler detection.
 ******************************************************************************/
/*@{*/
#define POC_COMPILER_UNKNOWN_ID 0
#define POC_COMPILER_GCC_ID 1
#define POC_COMPILER_ICC_ID 2
#define POC_COMPILER_MSVC_ID 4
#define POC_COMPILER_OPENCL_GENERIC_ID 8
#define POC_COMPILER_NVCC_ID 16
/*@}*/


/***************************************************************************//**
 * @name Predefined compiler strings.
 *
 * See Intel C++ Compiler Documentation.
 * See http://predef.sourceforge.net/index.php for macros defined by language standards, compilers, libraries, etc. The
 * documents in CVS have significantly less errors than the website.
 ******************************************************************************/
/*@{*/
#define POC_COMPILER_UNKNOWN_STRING "Unknown compiler"
#define POC_COMPILER_GCC_STRING "GNU GCC"
#define POC_COMPILER_MSVC_STRING "Microsoft Visual Studio C++"
#define POC_COMPILER_ICC_STRING "Intel C/C++"
#define POC_COMPILER_OPENCL_GENERIC_STRING "Generic OpenCL compiler"
#define POC_COMPILER_NVCC_STRING "Nvidia NVCC"
/*@}*/

/***************************************************************************//**
 * @name Compiler version.
 ******************************************************************************/
/*@{*/
#define POC_COMPILER_UNKNOWN_VERSION -1
/*@}*/

/***************************************************************************//**
 * @name Compiler standardized versions by vendor/creator.
 ******************************************************************************/
/*@{*/
#define POC_COMPILER_MSVC_VC6_STANDARDIZED_VERSION 120000000L
#define POC_COMPILER_MSVC_VC2003_STANDARDIZED_VERSION 130000000L
#define POC_COMPILER_MSVC_VC2005_STANDARDIZED_VERSION 140000000L
#define POC_COMPILER_MSVC_VC2008_STANDARDIZED_VERSION 150000000L

#define POC_COMPILER_GCC_GCC_2_9_STANDARDIZED_VERSION 20900L
#define POC_COMPILER_GCC_GCC_3_0_STANDARDIZED_VERSION 30000L
#define POC_COMPILER_GCC_GCC_3_1_STANDARDIZED_VERSION 30100L
#define POC_COMPILER_GCC_GCC_3_2_STANDARDIZED_VERSION 30200L
#define POC_COMPILER_GCC_GCC_3_3_STANDARDIZED_VERSION 30400L
#define POC_COMPILER_GCC_GCC_3_4_STANDARDIZED_VERSION 30400L
#define POC_COMPILER_GCC_GCC_4_0_STANDARDIZED_VERSION 40000L
#define POC_COMPILER_GCC_GCC_4_1_STANDARDIZED_VERSION 40100L
#define POC_COMPILER_GCC_GCC_4_2_STANDARDIZED_VERSION 40200L
#define POC_COMPILER_GCC_GCC_4_3_STANDARDIZED_VERSION 40300L
#define POC_COMPILER_GCC_GCC_4_4_STANDARDIZED_VERSION 40400L

# define POC_COMPILER_ICC_ICC1000_STANDARDIZED_VERSION 1000L
# define POC_COMPILER_ICC_ICC1100_STANDARDIZED_VERSION 1100L
/*@}*/


#if !defined(POC_COMPILER_DISABLE_AUTODETECT) && !defined(POC_DISABLE_AUTODETECT)


/*******************************************************************************
 * Detect compiler.
 ******************************************************************************/

/* Detect gcc (and therefor g++).
 */
#if defined(__GNUC__)
#   define POC_COMPILER_GCC POC_COMPILER_GCC_ID
#   if defined(__GNUC_PATCHLEVEL__)
#       define POC_COMPILER_GCC_VERSION (__GNUC__ * 10000L \
+ __GNUC_MINOR__ * 100L \
+ __GNUC_PATCHLEVEL__ )
#   else
#       define POC_COMPILER_GCC_VERSION (__GNUC__ * 10000L \
+ __GNUC_MINOR__ * 100L )
#   endif
#endif

/* Detect Microsoft Visual Studio Compiler.
 */
#if defined(_MSC_VER)
#   define POC_COMPILER_MSVC POC_COMPILER_MSVC_ID
#   if defined(_MSC_FULL_VER)
#       define POC_COMPILER_MSVC_VERSION (_MSC_FULL_VER + 0)
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   else
#       define POC_COMPILER_MSVC_VERSION (_MSC_VER * 100000L)
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#endif

/**
 * @todo TODO: Refactor to extract NVCC compiler version (if possible).
 */
#if defined(__CUDACC__)
#   define POC_COMPILER_NVCC POC_COMPILER_NVCC_ID
#   define POC_COMPILER_NVCC_VERSION POC_COMPILER_UNKNOWN_VERSION
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

/**
 * @todo TODO: Refactor to extract OpenCL compiler version and compiler vendor.
 */
#if defined(__OPENCL_VERSION__)
#   define POC_COMPILER_OPENCL_GENERIC POC_COMPILER_OPENCL_GENERIC_ID
#   define POC_COMPILER_OPENCL_GENERIC_VERSION POC_COMPILER_UNKNOWN_VERSION
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif


/* Detect Intel compiler.
 *
 * Intel compiler detection must happen after checks for GCC and MSVC because these compiler might be used as hosts
 * by ICC and their settings are needed by the following ICC detection preprocessor constructs.
 *
 * Intel's compiler often uses the systems native compiler infrastructure. If a system has Gnu GCC installed
 * @c POC_COMPILER_GCC is undefined - this is not the compiler used, but as its infrastructure is used
 * @c POC_COMPILER_ICC_GCC is used. @c POC_COMPILER_ICC_GCC is also used to prefix the detected Gnu GCC 
 * version and string describing it.
 */
#if defined(__ICC) || defined(__INTEL_COMPILER)
#   define POC_COMPILER_ICC POC_COMPILER_ICC_ID
#   define POC_COMPILER_ICC_VERSION __INTEL_COMPILER + 0
#   if defined(POC_COMPILER_GCC)
#       define POC_COMPILER_ICC_HOST_GCC POC_COMPILER_GCC_ID
#       define POC_COMPILER_ICC_HOST_GCC_STRING POC_COMPILER_GCC_STRING
#       define POC_COMPILER_ICC_HOST_GCC_VERSION POC_COMPILER_GCC_VERSION
#       define POC_COMPILER_ICC_HOST POC_COMPILER_GCC_ID
#       define POC_COMPILER_ICC_HOST_VERSION POC_COMPILER_GCC_VERSION
#       define POC_COMPILER_ICC_HOST_STRING POC_COMPILER_GCC_STRING
#       undef POC_COMPILER_GCC
#   elif defined(POC_COMPILER_MSVC)
#       define POC_COMPILER_ICC_HOST_MSVC POC_COMPILER_MSVC_ID
#       define POC_COMPILER_ICC_HOST_MSVC_VERSION POC_COMPILER_MSVC_VERSION
#       define POC_COMPILER_ICC_HOST_MSVC_STRING POC_COMPILER_MSVC_STRING
#       define POC_COMPILER_ICC_HOST POC_COMPILER_MSVC_ID
#       define POC_COMPILER_ICC_HOST_STRING POC_COMPILER_MSVC_STRING
#       define POC_COMPILER_ICC_HOST_VERSION POC_COMPILER_MSVC_VERSION
#       undef POC_COMPILER_MSVC
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   elif
#       define POC_COMPILER_ICC_HOST_UNKNOWN POC_COMPILER_UNKNOWN_ID
#       define POC_COMPILER_ICC_HOST_UNKNOWN_VERSION POC_COMPILER_UNKNOWN_VERSION
#       define POC_COMPILER_ICC_HOST_UNKNOWN_STRING POC_COMPILER_UNKNOWN_STRING
#       define POC_COMPILER_ICC_HOST POC_COMPILER_UNKNOWN_ID
#       define POC_COMPILER_ICC_HOST_STRING POC_COMPILER_UNKNOWN_STRING
#       define POC_COMPILER_ICC_HOST_VERSION POC_COMPILER_UNKNOWN_VERSION
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#endif







/*******************************************************************************
 * Determine @c POC_COMPILER, @c POC_COMPILER_STRING, and 
 * @c POC_COMPILER_VERSION based on the detected compiler.
 ******************************************************************************/

#if defined(POC_COMPILER_GCC)
#   define POC_COMPILER POC_COMPILER_GCC_ID
#   define POC_COMPILER_STRING POC_COMPILER_GCC_STRING
#   define POC_COMPILER_VERSION POC_COMPILER_GCC_VERSION
#endif

#if defined(POC_COMPILER_MSVC)
#   define POC_COMPILER POC_COMPILER_MSVC_ID
#   define POC_COMPILER_STRING POC_COMPILER_MSVC_STRING
#   define POC_COMPILER_VERSION POC_COMPILER_MSVC_VERSION
#endif

#if defined(POC_COMPILER_NVCC)
#   define POC_COMPILER POC_COMPILER_NVCC_ID
#   define POC_COMPILER_STRING POC_COMPILER_NVCC_STRING
#   define POC_COMPILER_VERSION POC_COMPILER_NVCC_VERSION
#endif

#if defined(POC_COMPILER_OPENCL_GENERIC)
#   define POC_COMPILER POC_COMPILER_OPENCL_GENERIC_ID
#   define POC_COMPILER_STRING POC_COMPILER_OPENCL_GENERIC_STRING
#   define POC_COMPILER_VERSION POC_COMPILER_OPENCL_GENERIC_VERSION
#endif


/* 
 * Icc detection must be last to overwrite values that might have been set by 
 * host compilers like GCC or MSVC.
 */
#if defined(POC_COMPILER_ICC)
#   define POC_COMPILER POC_COMPILER_ICC_ID
#   define POC_COMPILER_STRING POC_COMPILER_ICC_STRING
#   define POC_COMPILER_VERSION POC_COMPILER_ICC_VERSION
#endif


#endif /* !defined(POC_COMPILER_DISABLE_AUTODETECT) && !defined(POC_DISABLE_AUTODETECT) */



/*******************************************************************************
 * No known compiler, compiler string, or compiler version detected - set to 
 * unknown.
 ******************************************************************************/

#if !defined(POC_COMPILER)
#   define POC_COMPILER_UNKNOWN POC_COMPILER_UNKNOWN_ID
#   define POC_COMPILER POC_COMPILER_UNKNOWN_ID
#   error Compiler unknown.
#endif

#if !defined(POC_COMPILER_STRING)
#   define POC_COMPILER_STRING POC_COMPILER_UNKNOWN_STRING
#   error Compiler string unknown.
#endif

#if !defined(POC_COMPILER_VERSION)
#   define POC_COMPILER_VERSION POC_COMPILER_UNKNOWN_VERSION
#   error Compiler version unknown.
#endif


/*******************************************************************************
 * Error check
 * Exactly one main compiler must have been choosen - xor tests to find possible
 * error.
 * The main compiler can have a host compiler (see @c POC_COMPILER_ICC for an 
 * example).
 ******************************************************************************/
#if defined(POC_LANG_COMPILER_GCC) && \
(defined(POC_COMPILER_MSVC) || \
 defined(POC_COMPILER_ICC) || \
 defined(POC_COMPILER_NVCC) || \
 defined(POC_COMPILER_OPENCL_GENERIC) || \
 defined(POC_COMPILER_UNKNOWN))
#   error Exactly one compiler must be selected.
#elif defined(POC_LANG_COMPILER_MSVC) && \
(defined(POC_COMPILER_GCC) || \
defined(POC_COMPILER_ICC) || \
defined(POC_COMPILER_NVCC) || \
defined(POC_COMPILER_OPENCL_GENERIC) || \
defined(POC_COMPILER_UNKNOWN))
#   error Exactly one compiler must be selected.
#elif defined(POC_LANG_COMPILER_ICC) && \
(defined(POC_COMPILER_MSVC) || \
defined(POC_COMPILER_GCC) || \
defined(POC_COMPILER_NVCC) || \
defined(POC_COMPILER_OPENCL_GENERIC) || \
defined(POC_COMPILER_UNKNOWN))
#   error Exactly one compiler must be selected.
#elif defined(POC_LANG_COMPILER_NVCC) && \
(defined(POC_COMPILER_MSVC) || \
defined(POC_COMPILER_ICC) || \
defined(POC_COMPILER_GCC) || \
defined(POC_COMPILER_OPENCL_GENERIC) || \
defined(POC_COMPILER_UNKNOWN))
#   error Exactly one compiler must be selected.
#elif defined(POC_COMPILER_OPENCL_GENERIC) && \
(defined(POC_COMPILER_MSVC) || \
defined(POC_COMPILER_ICC) || \
defined(POC_COMPILER_NVCC) || \
defined(POC_COMPILER_GCC) || \
defined(POC_COMPILER_UNKNOWN))
#   error Exactly one compiler must be selected.
#elif defined(POC_COMPILER_UNKNOWN) && \
(defined(POC_COMPILER_MSVC) || \
defined(POC_COMPILER_ICC) || \
defined(POC_COMPILER_NVCC) || \
defined(POC_COMPILER_GCC) || \
defined(POC_COMPILER_OPENCL_GENERIC))
#   error Exactly one compiler must be selected.
#endif



#endif /* !defined(POC_COMPILER_HEADER_DISABLE_DEF_UNDEF) */

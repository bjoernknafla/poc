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
 * See poc_arch.h for details.
 *
 * @attention This header doesn't have header guards to allow successive inclusion of it and its sibling 
 *            poc_lang_undef.h . If header guards are wanted or needed use 
 *            poc.h or poc_lang.h instead.
 */

/* Only allow definition of POC programming language macros if poc_lang.h hasn't been included 
 * in this compilation unit.
 */
#if !defined(POC_LANG_HEADER_DISABLE_DEF_UNDEF)



/* Include macros prefixed with POC_COMPILER
 */
#include "poc_compiler_def.h"

/**
 * @todo TODO: Add detection of C++0x the moment they finalize the version number 
 *       stored in @c __cplusplus and adapt the @c POC_LANG_CPP_CPP2010 
 *       accordingly.
 */

/***************************************************************************//**
 * @name Predefined programming language ids
 *
 * Ids of later standards of the same language have higher values, e.g.
 * @c POC_LANG_C_C99_ID is greater than @c POC_LANG_C_C89_ID .
 ******************************************************************************/
/*@{*/
#define POC_LANG_UNKNOWN_ID 0
#define POC_LANG_C_UNKNOWN_ID 1
#define POC_LANG_C_C89_ID 2
#define POC_LANG_C_C99_ID 4
#define POC_LANG_CPP_UNKNOWN_ID 8
#define POC_LANG_CPP_CPP98_ID 16
#define POC_LANG_CPP_CPP2010_ID 32
#define POC_LANG_OBJC_UNKNOWN_ID 64
#define POC_LANG_OPENCL_UNKNOWN_ID 128
/*@}*/

/***************************************************************************//**
 * @name Predefined programming language strings
 ******************************************************************************/
/*@{*/
#define POC_LANG_UNKNOWN_STRING "Unknown language"
#define POC_LANG_C_UNKNOWN_STRING "C unknown version"
#define POC_LANG_C_C89_STRING "C89"
#define POC_LANG_C_C99_STRING "C99"
#define POC_LANG_CPP_UNKNOWN_STRING "C++ unknown version"
#define POC_LANG_CPP_CPP98_STRING "C++98"
#define POC_LANG_CPP_CPP2010_STRING "C++2010"
#define POC_LANG_OBJC_UNKNOWN_STRING "Objective-C unknown version"
#define POC_LANG_OPENCL_UNKNOWN_STRING "OpenCL unknown version"
/*@}*/

/***************************************************************************//**
 * @name Predefined programming language standard version numbers
 ******************************************************************************/
/*@{*/
#define POC_LANG_C_C89_STANDARDIZED_VERSION 199409L
#define POC_LANG_C_C99_STANDARDIZED_VERSION 199901L
#define POC_LANG_CPP_CPP98_STANDARDIZED_VERSION 199711L
/* #define POC_LANG_CPP_CPP2010_STANDARDIZED_VERSION 2010??L */
/*@}*/


#if !defined(POC_LANG_DISABLE_AUTODETECT) && !defined(POC_DISABLE_AUTODETECT)



/* See http://www.velocityreviews.com/forums/t278643-class-static-variables-amp-stdcversion.html for explanation
 * why to add @c 0 to a preprocessor symbol (if a symbol is defined but doesn't represent a number the @code +0 @endcode
 * transforms it into a number).
 */
#if defined(__STDC__)
# /* C89 with amendment from 1995 contains @c __STD_VERSION__ */
#   if defined(__STDC_VERSION__) && ((__STDC_VERSION__ + 0) == POC_LANG_C_C89_STANDARDIZED_VERSION)
#       define POC_LANG_C POC_LANG_C_C89_ID
#       define POC_LANG_C_C89 POC_LANG_C_C89_ID
#       define POC_LANG_C_STRING POC_LANG_C_C89_STRING
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   elif defined(__STDC_VERSION__) && ((__STDC_VERSION__ + 0) == POC_LANG_C_C99_STANDARDIZED_VERSION)
#       define POC_LANG_C POC_LANG_C_C99_ID
#       define POC_LANG_C_C99 POC_LANG_C_C99_ID
#       define POC_LANG_C_STRING POC_LANG_C_C99_STRING
#   else
#       define POC_LANG_C POC_LANG_C_C89_ID
#       define POC_LANG_C_C89 POC_LANG_C_C89_ID
#       define POC_LANG_C_STRING POC_LANG_C_C89_STRING
#   endif
#endif


/* See http://www.velocityreviews.com/forums/t278643-class-static-variables-amp-stdcversion.html for explanation
 * why to add @c 0 to a preprocessor symbol (if a symbol is defined but doesn't represent a number the @c +0 
 * transforms it into a number).
 */
#if defined(__cplusplus)
#   if ((__cplusplus + 0) == POC_LANG_CPP_CPP98_STANDARDIZED_VERSION)
#       define POC_LANG_CPP POC_LANG_CPP_CPP98_ID
#       define POC_LANG_CPP_CPP98 POC_LANG_CPP_CPP98_ID
#       define POC_LANG_CPP_STRING POC_LANG_CPP_CPP98_STRING
#   else
#       define POC_LANG_CPP POC_LANG_CPP_UNKNOWN_ID
#       define POC_LANG_CPP_STRING POC_LANG_CPP_UNKNOWN_STRING
#   endif
#endif


#if defined(__OBJC__)
#   define POC_LANG_OBJC POC_LANG_OBJC_UNKNOWN_ID
#   define POC_LANG_OBJC_STRING POC_LANG_OBJC_UNKNOWN_STRING
/**
 * @todo TODO: Check if @c OBJC_NEW_PROPERTIES is a documented and therefore reliable macro or not.
 */
#/*   if defined(OBJC_NEW_PROPERTIES) */
#/*    endif */
#endif


#if defined(__OPENCL_VERSION__)
#   define POC_LANG_OPENCL POC_LANG_OPENCL_UNKNOWN_ID
#   define POC_LANG_OPENCL_STRING POC_LANG_OPENCL_UNKNOWN_STRING
#   /* define POC_LANG_OPENCL_VERSION __OPENCL_VERSION__ */
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif




/*******************************************************************************
 * Detect language specific settings/defines.
 ******************************************************************************/

#if defined(POC_LANG_C_C99)
#   define POC_LANG_C_TYPE_BOOL_SUPPORT 1
#   define POC_LANG_C_TYPE_LONG_LONG_SUPPORT 1
#   define POC_LANG_C_TYPE_LONG_DOUBLE_SUPPORT 1
#   define POC_LANG_C_HEADER_STDBOOL_SUPPORT 1
#   define POC_LANG_C_HEADER_STDINT_SUPPORT 1
#   define POC_LANG_C_HEADER_STDBOOL_SUPPORT 1
#   /* Hosted C99 implementation. */
#   if defined(__STDC_HOSTED__) && (1 == __STDC_HOSTED__)
#       define POC_LANG_C_HEADER_INTTYPES_SUPPORT 1
#       define POC_LANG_C_TYPE_COMPLEX_SUPPORT 1
#       define POC_LANG_C_TYPE_IMAGINARY_SUPPORT 1
#   /* Freestanding C99 implementation
#    * It isn't specified if freestanding implementations support complex data types.
#    */
#   elif defined(__STDC_HOSTED__) && (0 == __STDC_HOSTED__)  
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.      
#   endif
#   /* Compiler performs floating point arithmetic according to the IEC 60559 standard, also known as the 
#    * IEEE 754 standard.
#    */
#   if defined(__STDC_IEC_559__) && (1 == __STDC_IEC_559__) 
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   /* Compiler performs complex arithmetic according to the IEC 60559 standard. */
#   if defined(__STD_IEC_559_COMPLEX__) && (1 == __STD_IEC_559_COMPLEX__) 
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   /* Values of the type @c wchar_t are represented by the codes in the ISO/IEC 10646 standard. The macro contains the 
#    * standard revision as an integral value encoded as the year and month if the revision, @c yyyymmL .
#    */
#   if defined(__STDC_ISO_10646__) 
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#endif



/* Detect if RTTI is for sure enabled for C++. 
 * @attention RTTI might even be enabled if the tested macros aren't defined.
 */
#if defined(POC_LANG_CPP)
#   if defined(POC_COMPILER_GCC) && defined(__GXX_RTTI)
#       define POC_LANG_CPP_RTTI_SUPPORT 1
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   if defined(POC_COMPILER_MSVC) && defined(_CPPRTTI)
#       define POC_LANG_CPP_RTTI_SUPPORT 1
#   endif
#   if defined(POC_COMPILER_ICC) && defined(__INTEL_RTTI__)
#       define POC_LANG_CPP_RTTI_SUPPORT 1
#   endif
#endif

/* Detect if exceptions are enabled for C++
 */
#if defined(POC_LANG_CPP)
#   if defined(POC_COMPILER_GCC) && defined(__EXCEPTIONS)
#       define POC_LANG_CPP_EXCEPTIONS_SUPPORT 1
#   endif
#   if defined(POC_COMPILER_MSVC) && defined(_CPPUNWIND)
#       define POC_LANG_CPP_EXCEPTIONS_SUPPORT 1
#   endif
#   if defined(POC_COMPILER_ICC) && defined(__EXCEPTIONS)
#       define POC_LANG_CPP_EXCEPTIONS_SUPPORT 1
#   endif
#endif


#if defined (POC_LANG_OPENCL)
#   /* Detect extensions. */
#   if defined(CL_DEVICE_ADDRESS_SPACE)
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   if defined(cl_khr_fp64)
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   if defined(cl_khr_select_fprounding_mode)
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#       /* Possible values for @c __ROUNDING_MODE__ are @code rte, rtz, rtp, rtz @endcode . */
#   endif
#   if defined(cl_khr_global_int32_base_atomics)
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   if defined(cl_khr_global_int32_extended_atomics)
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   if defined(cl_khr_local_int32_base_atomics)
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   if defined(cl_khr_local_int32_extended_atomics)
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   if defined(cl_khr_int64_base_atomics)
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   if defined(cl_khr_int64_extended_atomics)
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   if defined(cl_khr_3d_image_writes)
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   if defined(cl_khr_byte_addressable_store)
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   if defined(cl_khr_fp16)
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif




/*******************************************************************************
 * Set @c POC_LANG and @c POC_LANG_STRING.
 ******************************************************************************/

#if defined(POC_LANG_C)
#   define POC_LANG POC_LANG_C
#   define POC_LANG_STRING POC_LANG_C_STRING
#endif

#if defined(POC_LANG_CPP)
#   undef POC_LANG
#   undef POC_LANG_STRING
#   define POC_LANG POC_LANG_CPP
#   define POC_LANG_STRING POC_LANG_CPP_STRING
#endif

#if defined(POC_LANG_OBJC)
#   undef POC_LANG
#   undef POC_LANG_STRING
#   define POC_LANG POC_LANG_OBJC
#   define POC_LANG_STRING POC_LANG_OBJC_STRING
#endif

#if defined(POC_LANG_OPENCL)
#   undef POC_LANG
#   undef POC_LANG_STRING
#   define POC_LANG POC_LANG_OPENCL
#   define POC_LANG_STRING POC_LANG_OBJC_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif




#endif /* !defined(POC_LANG_DISABLE_AUTODETECT) && !defined(POC_DISABLE_AUTODETECT) */



/* No known programming language detected.
 */

#if !defined(POC_LANG)
#   define POC_LANG_UNKNOWN POC_LANG_UNKNOWN_ID
#   define POC_LANG POC_LANG_UNKNOWN_ID
#   error Unknown programming language.
#endif

#if !defined(POC_LANG_STRING)
#   define POC_LANG_STRING POC_LANG_UNKNOWN_STRING
#   error Unknown programming language string.
#endif


/*******************************************************************************
 * Error check
 ******************************************************************************/


/* Commented out because need to think why POC_LANG_C and POC_LANG_CPP shouldn't be defined at the same time. 
 */ 
/* Exactly one programming language must have been chosen - xor tests to find possible error.
#if defined(POC_LANG_C) && \
(defined(POC_LANG_CPP) || \
defined(POC_LANG_OBJC) || \
defined(POC_LANG_OPENCL) || \
defined(POC_LANG_UNKNOWN))
#   error Exactly one programming language must be selected.
#elif defined(POC_LANG_CPP) && \
(defined(POC_LANG_C) || \
defined(POC_LANG_OBJC) || \
defined(POC_LANG_OPENCL) || \
defined(POC_LANG_UNKNOWN))
#   error Exactly one programming language must be selected.
#elif defined(POC_LANG_OBJC) && \
(defined(POC_LANG_CPP) || \
defined(POC_LANG_C) || \
defined(POC_LANG_OPENCL) || \
defined(POC_LANG_UNKNOWN))
#   error Exactly one programming language must be selected.
#elif defined(POC_LANG_OPENCL) && \
(defined(POC_LANG_CPP) || \
defined(POC_LANG_OBJC) || \
defined(POC_LANG_C) || \
defined(POC_LANG_UNKNOWN))
#   error Exactly one programming language must be selected.
#elif defined(POC_LANG_UNKNOWN) && \
(defined(POC_LANG_CPP) || \
defined(POC_LANG_OBJC) || \
defined(POC_LANG_OPENCL) || \
defined(POC_LANG_C))
#   error Exactly one programming language must be selected.
#endif
*/


#endif /* !defined(POC_LANG_HEADER_DISABLE_DEF_UNDEF) */



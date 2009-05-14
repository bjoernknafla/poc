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
 * See poc_primary_types.h for details.
 *
 * @attention This header doesn't have header guards to allow successive inclusion of it and its sibling 
 *            poc_primary_types_undef.h . If header guards are wanted or needed use 
 *            poc.h or poc_primary_types.h instead.
 *
 * @todo TODO: Handle @c wchar_t .
 * @todo TODO: Add tests to poc_diagnose.c .
 */




/* Only allow definition of POC primary types if poc_primary_types.h hasn't been 
 * included in this compilation unit.
 */
#if !defined(POC_PRIMARY_TYPES_HEADER_DISABLE_DEF_UNDEF)




/* If @c POC_PRIMARY_TYPES_DISABLE_AUTODETECT is defined no automatic 
 * primary type detection should take place.
 */
#if !defined(POC_PRIMARY_TYPES_DISABLE_AUTODETECT) && !defined(POC_DISABLE_AUTODETECT)



#include "poc_lang_def.h"
#include "poc_compiler_def.h"
#include "poc_data_model_def.h"



/*
 * Define @c POC_LONG_LONG and @c POC_UNSIGNED_LONG_LONG and 
 * @c POC_LONG_DOUBLE 
 */
#if defined(POC_LANG_C) || defined(POC_LANG_CPP)
#   define POC_LONG_DOUBLE long double
#   if defined(POC_LANG_C_TYPE_LONG_LONG_SUPPORT) || defined(POC_LANG_CPP_TYPE_LONG_LONG_SUPPORT)
#       define POC_LONG_LONG long long
#       define POC_UNSIGNED_LONG_LONG unsigned long long
#   endif
#endif



/* 
 * Define @c POC_BOOL, @c POC_TRUE, and @c POC_FALSE 
 */
#if defined(POC_LANG_CPP)
#   define POC_BOOL bool
#   define POC_TRUE true
#   define POC_FALSE false
#elif defined(POC_LANG_OBJC)
#   define POC_BOOL BOOL
#   define POC_TRUE YES
#   define POC_FALSE NO
#elif defined(POC_LANG_OPENCL)
#   define POC_BOOL bool
#   define POC_TRUE true
#   define POC_FALSE false
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#elif (POC_LANG_C < POC_LANG_C_C99_ID)
#   define POC_BOOL int
#   define POC_TRUE 1
#   define POC_FALSE 0
#elif(POC_LANG_C >= POC_LANG_C_C99_ID)
#   define POC_BOOL _Bool
#   define POC_TRUE 1
#   define POC_FALSE 0
#else
#   error Unknown boolean type of language.
#endif




/* 
 * Define platform independent sized integral, pointer, and 
 * floating point types 
 */
#if defined(POC_COMPILER_MSVC) || (POC_COMPILER_ICC_HOST_MSVC)
#   /* MSVC compiler documentation defines type sizes */
#   define POC_BYTE unsigned char
#   define POC_CHAR char
#   define POC_SIGNED_CHAR signed char
#   define POC_UNSIGNED_CHAR unsigned char
#   define POC_INT8 signed char
#   define POC_UINT8 unsigned char
#   define POC_INT16 short
#   define POC_UINT16 unsigned short
#   define POC_INT32 int
#   define POC_UINT32 unsigned int
#   /* See http://msdn.microsoft.com/en-us/library/94z15h2c.aspx */
#   if defined(_INTEGRAL_MAX_BITS) && (_INTEGRAL_MAX_BITS >= 64)
#       define POC_INT64 __int64 /* Defined since Visual Studio 6.0 , printf use I64 */
#       define POC_UINT64 unsigned __int64
#   endif
#   define POC_FLOAT32 float
#   define POC_FLOAT64 double
#   if defined(POC_DATA_MODEL_ILP32)
#       define POC_INTPTR_T int
#       define POC_UINTPTR_T unsigned int
#       define POC_PTRDIFF_T int
#       define POC_SIZE_T unsigned int
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   elif defined(POC_DATA_MODEL_LLP64)
#       define POC_INTPTR_T __int64
#       define POC_UINTPTR_T unsigned __int64
#       define POC_PTRDIFF_T __int64
#       define POC_SIZE_T unsigned __int64
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   else
#       Unknown data model for MSVC compiler.
#   endif
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#elif defined(POC_LANG_OPENCL)
#   /* Based on OpenCL Specification 1.0.33 */
#   define POC_BYTE unsigned char
#   define POC_CHAR char
#   define POC_SIGNED_CHAR signed char
#   define POC_UNSIGNED_CHAR unsigned char
#   define POC_INT8 signed char
#   define POC_UINT8 unsigned char
#   define POC_INT16 short
#   define POC_UINT16 unsigned short
#   define POC_INT32 int
#   define POC_UINT32 unsigned int
#   define POC_INT64 long
#   define POC_UINT64 unsigned long
#   define POC_INTPTR_T intptr_t
#   define POC_UINTPTR_T uintptr_t
#   define POC_PTRDIFF_T ptrdiff_t
#   define POC_SIZE_T size_t
#   define POC_FLOAT32 float
#   define POC_FLOAT64 double
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#elif defined(POC_DATA_MODEL_ILP32)
#   /* As the ILP32 data model doesn't specify a 64bit type or the size of @c float or @c double
#    * @c POC_INT64 and @c POC_UINT64 aren't defined and @c POC_FLOAT32 and
#    * @c POC_FLOAT64 might be incorrect 
#    */
#   define POC_BYTE unsigned char
#   define POC_CHAR char
#   define POC_SIGNED_CHAR signed char
#   define POC_UNSIGNED_CHAR unsigned char
#   define POC_INT8 signed char
#   define POC_UINT8 unsigned char
#   define POC_INT16 short
#   define POC_UINT16 unsigned short
#   define POC_INT32 int
#   define POC_UINT32 unsigned int
#   if defined(__SIZEOF_LONG_LONG__) && (__SIZEOF_LONG_LONG__ == 8) && defined(POC_LONG_LONG)
#       define POC_INT64 long long
#       define POC_UINT64 unsigned long long
#   else
#       /* define POC_INT64 not defined */
#       /* define POC_UINT64 not defined */
#   endif
#   define POC_INTPTR_T int
#   define POC_UINTPTR_T unsigned int
#   define POC_PTRDIFF_T int
#   define POC_SIZE_T unsigned int
#   define POC_FLOAT32 float /* This must be tested... No guarantee by standard or GCC or ICC */
#   define POC_FLOAT64 double /* This must be tested... No guarantee by standard or GCC or ICC */
#elif defined(POC_DATA_MODEL_LP64)
#   /* As the ILP64 data model doesn't specify the size of @c float or @c double
#    * @c POC_FLOAT32 and @c POC_FLOAT64 might be incorrect 
#    */
#   define POC_BYTE unsigned char
#   define POC_CHAR char
#   define POC_SIGNED_CHAR signed char
#   define POC_UNSIGNED_CHAR unsigned char
#   define POC_INT8 signed char
#   define POC_UINT8 unsigned char
#   define POC_INT16 short
#   define POC_UINT16 unsigned short
#   define POC_INT32 int
#   define POC_UINT32 unsigned int
#   define POC_INT64 long
#   define POC_UINT64 unsigned long
#   define POC_INTPTR_T long
#   define POC_UINTPTR_T unsigned long
#   define POC_PTRDIFF_T long
#   define POC_SIZE_T unsigned long
#   define POC_FLOAT32 float /* This must be tested... No guarantee by standard or GCC or ICC */
#   define POC_FLOAT64 double /* This must be tested... No guarantee by standard or GCC or ICC */
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#else 
#   /* Use the data model to at least try to define the platform types */
#   error Unknown integral, floating point, and pointer bit-sizes.
#endif





/* 
 * For GCC greater than version 4.3.0 check the byte sized of @c POC_FLOAT32 and
 * @c POC_FLOAT64.
 */
#if defined(POC_COMILER_GCC) && (POC_COMPILER_GCC_VERSION >= POC_COMPILER_GCC_GCC_4_3_STANDARDIZED_VERSION)
#   if (__SIZEOF_FLOAT__ != 4)
#       error Size of POC_FLOAT32 isn't 32 bit (4 byte).
#   endif
#   if (__SIZEOF_DOUBLE__ != 8)
#       error Size of POC_FLOAT64 isn't 64 bit (8 byte).
#   endif
#endif


#endif /* !defined(POC_PRIMARY_TYPES_DISABLE_AUTODETECT) && !defined(POC_DISABLE_AUTODETECT) */


#endif /* !defined(POC_PRIMARY_TYPES_HEADER_DISABLE_DEF_UNDEF) */

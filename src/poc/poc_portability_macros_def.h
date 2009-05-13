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
 * See poc_portability_macros.h for details.
 *
 * @attention This header doesn't have header guards to allow successive inclusion of it and its sibling 
 *            poc_portability_macros_undef.h . If header guards are wanted or needed use 
 *            poc.h or poc_portability_macros.h instead.
 *
 *
 * @todo TODO: Add @c POC_LONG_LONG_TYPE, @c POC_UNSIGNED_LONG_LONG_TYPE, @c POC_LONG_DOUBLE_TYPE .
 * @todo TODO: Add macros for different bit-sized integral and floating point types to simplify implementing @c stdint.h ?
 * @todo TODO: Handle @c wchar_t .
 * @todo TODO: Handle library import/export alas visible/hidden qualifiers.
 */

/* Only allow definition of POC portability macros if poc_portability_macros.h hasn't been included 
 * in this compilation unit.
 */
#if !defined(POC_PORTABILITY_MACROS_HEADER_DISABLE_DEF_UNDEF)


#include "poc_compiler_def.h"
#include "poc_lang_def.h"


/*******************************************************************************
 * Macros for @c POC_INLINE and @c POC_RESTRICT are defined if the compiler 
 * supports these keywords.
 ******************************************************************************/

#if defined(POC_LANG_C_C99)
#   define POC_INLINE inline
#   define POC_RESTRICT restrict
#elif defined(POC_LANG_CPP)
#   define POC_INLINE inline
#   define POC_RESTRICT
#else
#   define POC_INLINE
#   define POC_RESTRICT
#endif


/*******************************************************************************
 * Byte-sized stack memory alignment directives @c POC_ALIGN_BEGIN and 
 * @c POC_ALIGN_END .
 * 
 * Be carefull when using the alignment values that the value of 
 * @c POC_ALIGN_BEGIN( val ) and the value of the corresponding 
 * @c POC_ALIGN_END( val ) are equal.
 ******************************************************************************/

/**
 * @todo TODO: Add tests.
 * @todo TODO: Add checks in macros for alignment values that don't work on specific compilers.
 */

#if defined(POC_COMPILER_GCC)
#   define POC_ALIGN_BEGIN( ALIGN )
#   define POC_ALIGN_END( ALIGN ) __attribute__((__aligned__( ALIGN )))
#elif defined(POC_COMPILER_ICC)
#   define POC_ALIGN_BEGIN( ALIGN ) __declspec(align( ALIGN ))
#   define POC_ALIGN_END( ALIGN )
#elif defined(POC_COMPILER_MSVC)
#   define POC_ALIGN_BEGIN( ALIGN ) __declspec(align( ALIGN ))
#   define POC_ALIGN_END( ALIGN )
#else
#   error Unknown compiler. Alignment macros not implemented.
#endif

#define POC_ALIGN(DECL, ALIGN) POC_ALIGN_BEGIN(ALIGN) DECL POC_ALIGN_END(ALIGN)


#endif /* !defined(POC_PORTABILITY_MACROS_HEADER_DISABLE_DEF_UNDEF) */

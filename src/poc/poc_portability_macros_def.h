/*
 * Copyright (c) 2009, Bjoern Knafla
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the 
 * following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this list of conditions and the following 
 *   disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following 
 *   disclaimer in the documentation and/or other materials provided with the distribution.
 * - Neither the name of the Bjoern Knafla nor the names of its contributors may be used to 
 *   endorse or promote products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/// @TODO: Add @c POC_LONG_LONG_TYPE, @c POC_UNSIGNED_LONG_LONG_TYPE, @c POC_LONG_DOUBLE_TYPE .
/// @TODO: Add macros for different bit-sized integral and floating point types to simplify implementing @c stdint.h ?
/// @TODO: Handle @c wchar_t .
/// @TODO: Handle library import/export visible/hidden qualifiers.


#if !defined(POC_PORTABILITY_MACROS_HEADER_DISABLE_DEF_UNDEF)


#include "poc_compiler_def.h"
#include "poc_lang_def.h"

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


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Detect and set memory alignment directives.
// 
// Be carefull when using the alignment values that the value of @c POC_ALIGN_BEGIN( val ) and the value of the
// corresponding @c POC_ALIGN_END( val ) are equal.
//
// See @example platform_config_lang_test.cpp for an example how to use the alignment macros.
// 
// @todo Check if ALIGN is correctly used (do the directives assume bit-sized or byte-sized values?).
// @todo Implement.
// @todo Move alignment into its own header and possibly put it into the memory sub-project.
// @TODO: Add documentation how to use @c POC_ALIGN_BEGIN and @c POC_ALIGN_END with typedefs.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if defined(POC_COMPILER_GCC) // Uses byte-alignment-values
#   define POC_ALIGN_BEGIN( ALIGN )
#   define POC_ALIGN_END( ALIGN ) __attribute__((__aligned__( ALIGN )))
// #   define POC_ALIGN_MAX_BEGIN
// #   define POC_ALIGN_MAX_END __attribute__((__aligned__))
#elif defined(POC_COMPILER_ICC) // Uses byte-alignment-values, for Intel C++ 10.1 alignment values of 8 don't work.
#   define POC_ALIGN_BEGIN( ALIGN ) __declspec(align( ALIGN ))
#   define POC_ALIGN_END( ALIGN )
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#elif defined(POC_COMPILER_MSVC)
#   define POC_ALIGN_BEGIN( ALIGN ) __declspec(align( ALIGN ))
#   define POC_ALIGN_END( ALIGN )
#else
#   error Unknown compiler. Alignment macros not implemented.
#endif


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Detect and set visibility when importing or exporting symbols from libraries or DLLs.
//
// @todo Implement.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




#endif // !defined(POC_PORTABILITY_MACROS_HEADER_DISABLE_DEF_UNDEF)

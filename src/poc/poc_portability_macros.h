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

/**
 * @file
 *
 * Helper macros to allow portable and compiler-independent declaration of stack memory alignment of types, symbol import 
 * and export from libraries (not usable yet), and usage of C keywords like @c inline (@c POC_INLINE) or 
 * @c restrict (@c POC_RESTRICT).
 *
 * Wrap type declarations in @c POC_ALIGN_BEGIN(<byte-alignment>) and @c POC_ALIGN_END(<byte-alignment>). 
 *
 * Examples:
 * @code
 * struct POC_ALIGN_BEGIN(64) type_t 
 * {
 *     long var1;
 *     int var2;
 * } POC_ALIGN_END(64);
 * @endcode
 * or
 * @code
 * typedef a_type_t POC_ALIGN_BEGIN(16) typedefed_name POC_ALIGN_END(16);
 * @endcode
 *
 * For convenience include this header and don't use @c poc_portability_macros_def.h directly. Use the 
 * @code _def.h @endcode and @code _undef.h @encode files for fine grained control of the parts in the code where 
 * @c POC_ prefixed macros are defined (or undefined) but keep care for yourself that macros aren't redefined.
 * By including the POC headers without the @code _def.h @endcode or @code _undef.h @endcode postfix the defined macros
 * exist throughout the whole compilation unit and can't be undefined by including the corresponding 
 * @code _undef.h @endcode anymore.
 */


/// @def POC_RESTRICT
/// Defined to @c restrict if compiling for C99, otherwise empty.

/// @def POC_ALIGN_BEGIN( Align )
/// Wrapping beginning for a type aligned to @c Align bytes.

/// @def POC_ALIGN_END( Align )
/// Wrapping ending for a type aligned to @c Align bytes.

#ifndef POC_poc_portability_macros_H
#define POC_poc_portability_macros_H

#include "poc_compiler.h"

#include "poc_lang.h"

#include "poc_portability_macros_def.h"

// Disable macro undefines via including @code poc_portability_macros_undef.h @endcode and prevent re-defines from 
// accidential includes of @code poc_portability_macros_def.h @endcode .
#define POC_PORTABILITY_MACROS_HEADER_DISABLE_DEF_UNDEF

#endif // POC_poc_portability_macros_H

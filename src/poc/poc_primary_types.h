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
 * Collection of macros defining primary types like @c POC_BOOL, 
 * @c POC_LONG_LONG (if supported), @c POC_INTPTR_T, @c POC_UINTPTR_T,
 * @c POC_PTRDIFF_T, @c POC_SIZE_T, and sized types like @c POC_INT32,
 * @c POC_UINT32, @c POC_FLOAT32, and @c POC_FLOAT64.
 *
 * @attention The detection of sized types isn't fail-proof - compile and run
 *             @c poc_diagnose to check that all defines are correct.
 *
 * For convenience include this header and don't use poc_primary_types_def.h directly. Use the 
 * @c _def.h and @c _undef.h files for fine grained control of the parts in the code where 
 * @c POC_ prefixed macros are defined (or undefined) but keep care for yourself that macros aren't redefined.
 * By including the POC headers without the @c _def.h or @c _undef.h postfix the defined macros
 * exist throughout the whole compilation unit and can't be undefined by including the corresponding 
 * @c _undef.h anymore.
 */


/**
 * @def POC_BOOL
 *
 * Maps to the platforms bool type or to an integral type if no native boolean
 * type exists.
 */

/**
 * @def POC_TRUE
 *
 * Maps to a value representing a boolean @c true value.
 */

/**
 * @def POC_FALSE
 *
 * Maps to a value representing a boolean @c false value.
 */

/**
 * @def POC_LONG_LONG
 *
 * If defined a @c long @c long type exists, @c POC_LONG_LONG can then be used
 * instead of writing @c long @c long.
 */

/**
 * @def POC_UNSIGNED_LONG_LONG
 *
 * If defined a @c unsigned @c long @c long type exists,
 * @c POC_UNSIGNED_LONG_LONG can then be used instead of writing 
 * @c unsigned @c long @c long.
 */

/**
 * @def POC_LONG_DOUBLE
 *
 * If defined a @c long @c double floating point type exists, @c POC_LONG_DOUBLE
 * can then be used instead of writing @c long @c double.
 */

/**
 * @def POC_BYTE
 *
 * Unsigned integral type of size 8 bit / 1 byte.
 */

/**
 * @def POC_CHAR
 *
 * Placeholder for @c char.
 * @c char, @c unsigned @c char, and @c signed @c char are different types.
 */

/**
 * @def POC_SIGNED_CHAR
 *
 * Placeholder for @c signed @ char.
 * @c char, @c unsigned @c char, and @c signed @c char are different types.
 */

/**
 * @def POC_UNSIGNED_CHAR
 *
 * Placeholder for @c unsigned @c char.
 * @c char, @c unsigned @c char, and @c signed @c char are different types.
 */

/**
 * @def POC_INT8
 *
 * Signed integral type of size 8 bit / 1 byte.
 */

/**
 * @def POC_UINT8
 *
 * Unsigned integral type of size 8 bit / 1 byte.
 */

/**
 * @def POC_INT16
 *
 * Signed integral type of size 16 bit / 2 byte.
 */

/**
 * @def POC_UINT16
 *
 * Unigned integral type of size 16 bit / 2 byte.
 */

/**
 * @def POC_INT32
 *
 * Signed integral type of size 32 bit / 4 byte.
 */

/**
 * @def POC_UINT32
 *
 * Unsigned integral type of size 32 bit / 4 byte.
 */

/**
 * @def POC_INT64
 *
 * If defined, signed integral type of size 64 bit / 8 byte.
 */

/**
 * @def POC_UINT64
 *
 * If defined, unsigned integral type of size 64 bit / 8 byte.
 */

/**
 * @def POC_FLOAT32
 *
 * If defined, signed floating point type of size 32 bit / 4 byte.
 */

/**
 * @def POC_FLOAT64
 *
 * If defined, signed floating point type of size 64 bit / 8 byte.
 */

/**
 * @def POC_INTPTR_T
 *
 * Signed integral type that can hold the cast value of a pointer.
 */

/**
 * @def POC_UINTPTR_T
 *
 * Unsigned integral type that can hold the cast value of a pointer.
 */

/**
 * @def POC_PTRDIFF_T
 *
 * Signed integral value that can store the arithmetic difference betwenn two 
 * pointers.
 */

/**
 * @def POC_SIZE_T
 *
 * Unsigned type of size to address the greatest arrays, also return type of
 * the @c sizeof operator.
 */

#ifndef POC_poc_primary_types_H
#define POC_poc_primary_types_H


#include "poc_lang.h"
#include "poc_compiler.h"
#include "poc_data_model.h"


#include "poc_primary_types_def.h"

/* Disable macro undefines via including poc_portability_macros_undef.h and prevent re-defines from 
 * accidential includes of poc_portability_macros_def.h .
 */
#define POC_PRIMARY_TYPES_HEADER_DISABLE_DEF_UNDEF






#endif /* POC_poc_primary_types_H */

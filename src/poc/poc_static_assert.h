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
 * C++ only utility code - @code POC_STATIC_ASSERT( <compile-time-condition>, <message>) @endcode macro to check 
 * conditions at compile-time and generate a compiler error if the condition isn't met. Compareable to C++0x's 
 * @c static_assert keyword.
 *
 * For convenience include this header and don't use @c poc_static_assert_def.h directly. Use the @code _def.h @endcode 
 * and @code _undef.h @endcode files for fine grained control of the parts in the code where @c POC_ prefixed macros are 
 * defined (or undefined) but keep care for yourself that macros aren't redefined.
 * By including the POC headers without the @code _def.h @endcode or @code _undef.h @endcode postfix the defined macros
 * exist throughout the whole compilation unit and can't be undefined by including the corresponding 
 * @code _undef.h @endcode anymore.
 */

#ifndef POC_poc_poc_static_assert_H
#define POC_poc_poc_static_assert_H



// @todo TODO: Decide if undef @c POC_STATIC_ASSERT instead of generating a compile time error.
#if defined(POC_STATIC_ASSERT)
#   error POC_STATIC_ASSERT macro shouldn't be defined at this point.
#endif


#include "poc_preprocessor_utilities.h"

#include "poc_static_assert_def.h"

// Disable macro undefines via including @code poc_static_assert_undef.h @endcode and prevent re-defines from accidential
// includes of @code poc_static_assert_def.h @endcode .
#define POC_STATIC_ASSERT_HEADER_DISABLE_DEF_UNDEF


#endif // POC_poc_poc_static_assert_H

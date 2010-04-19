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
 * Collection of @c POC_LANG (prefixed) preprocessor macros to identify the programming language the compiler assumes 
 * the code to represent.
 * 
 * For example if the code is compiled as C++ according to the '98 standard,  @c POC_LANG_CPP_CPP98_ID is stored in 
 * @c POC_LANG and also the macro @c POC_LANG_CPP_CPP98 is defined with the previous id value. In this case 
 * @c POC_LANG_STRING is set to @c POC_LANG_CPP_CPP98_STRING . If the C++ standard version can't be identified 
 * @c POC_LANG_CPP_UNKNOWN_ID, @c POC_LANG_CPP_UNKNOWN, and @c POC_LANG_CPP_UNKNOWN_STRING are used accordingly.
 *
 * Certain other @c POC_LANG_ prefixed macros are defined to represent specific language features if they are certainly
 * detected (these language features might be available even if the macros aren't set though). For example if code is
 * compiled according to the C99 C standard the macro @c POC_LANG_C_TYPE_BOOL_SUPPORT is defined, too. See 
 * poc_lang_def.h for more details.
 *
 * For convenience include this header and don't use poc_lang_def.h directly. Use the 
 * _def.h and _undef.h files for fine grained control of the parts in the code where 
 * @c POC_ prefixed macros are defined (or undefined) but keep care for yourself that macros aren't redefined.
 * By including the POC headers without the @c _def.h or @c _undef.h postfix the defined macros
 * exist throughout the whole compilation unit and can't be undefined by including the corresponding 
 * @c _undef.h anymore.
 */

/**
 * @def POC_LANG
 * Stores a predefined value representing the programming language compiling for or @c POC_LANG_UNKNOWN_ID if the
 * language can't be identified (is unknown).
 */

/** 
 * @def POC_LANG_STRING
 * Stores a C character string describing the identified programming language the compiler assumes.
 */

/**
 * @def POC_LANG_UNKNOWN
 *
 * Defined if compiled programming language couldn't be detected.
 */

/**
 * @def POC_LANG_UNKNOWN_STRING
 *
 * Defined if compiled programming language couldn't be detected.
 */

#ifndef POC_poc_lang_H
#define POC_poc_lang_H

#include "poc_compiler.h"

#include "poc_lang_def.h"


/* Disable macro undefines via including poc_lang_undef.h and prevent re-defines from accidential
 * includes of poc_lang_def.h .
 */
#define POC_LANG_HEADER_DISABLE_DEF_UNDEF

#endif /* POC_poc_lang_H */

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
 * Collection of @c POC_ARCH (prefixed) preprocessor macros to identify the machine architecture compiling for.
 * 
 * For example if the code is compiled for a 64bit x86 machine the id @c POC_ARCH_X86_64_ID is combined with 
 * @c POC_ARCH_X86_ID (they are bit-wise or-ed together) and the result stored in @c POC_ARCH . Additionally
 * the macros @c POC_ARCH_X86_64 and @c POC_ARCH_X86 are defined with their respective id values. In this case 
 * @c POC_ARCH_STRING is set to @c POC_ARCH_X86_64_STRING , the most specific architecture description.
 *
 * To test if a certain machine architecture is represented, for example if comping for a Cell BE SPU see the
 * following example:
 * @code
 * if (POC_ARCH & POC_ARCH_CELL_SPU) {
 * ...
 * }
 * @endcode
 * or use @c POC_MATCHES from poc_preprocessor_utilities.h:
 * @code
 * if (POC_MATCHES(POC_ARCH, POC_ARCH_CELL_SPU)) {
 * ...
 * }
 * @endcode
 * or use @c POC_MATCHES_EXACTLY from poc_preprocessor_utilities.h if the values should be equal.
 *
 *
 * For convenience include this header and don't use poc_arch_def.h directly. Use the 
 * @c _def.h and @c _undef.h files for fine grained control of the parts in the code where 
 * @c POC_ prefixed macros are defined (or undefined) but keep care for yourself that macros aren't redefined.
 * By including the POC headers without the @c _def.h or @c _undef.h postfix the defined macros
 * exist throughout the whole compilation unit and can't be undefined by including the corresponding 
 * @c _undef.h anymore.
 */


/**
 * @def POC_ARCH
 *
 * Stores a predefined value representing the machine architecture compiling for or @c POC_ARCH_UNKNOWN_ID if the
 * architecture can't be identified (is unknown).
 */

/**
 * @def POC_ARCH_STRING
 *
 * Stores a C character string describing the identified machine architecture.
 */

#ifndef POC_poc_arch_H
#define POC_poc_arch_H

#include "poc_arch_def.h"

/* Disable macro undefines via including poc_arch_undef.h and prevent re-defines from accidential
 * includes of poc_arch_def.h .
 */
#define POC_ARCH_HEADER_DISABLE_DEF_UNDEF

#endif /* POC_poc_arch_H */

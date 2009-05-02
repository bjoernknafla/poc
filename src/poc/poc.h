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
 * Preprocessor symbols prefixed with @c POC_ to detect the target platform the code is compiled for and to allow
 * cross platform compatible keywords, for example to align data types on the stack.
 *
 * Use POC to detect the target platform the code unit is compiled for, for example:
 * - @c POC_ARCH stores an id identifying the machine architecture
 * - @c POC_COMPILER stores an id identifying the used compiler, @c POC_COMPILER_VERSION stores a number representing
 *   the compiler version
 * - @c POC_DATA_MODEL stores an id identifying the platforms data model alas the bit-count of integral, floating point,
 *   and pointer types.
 * - @c POC_ENDIAN stores an id identifying the endianess of the platform.
 * - @c POC_LANG stores an id identifying the language (C, C++, Objective-C, OpenCL, CUDA, etc.) compiling for.
 * - @c POC_OS stores an id identifying the target operating system.
 * 
 * Each of these preprocessor symbols (other than the ones ending with @code _VERSION @endcode) is acompanied by a macro 
 * with a @code _STRING @endcode postfix that stores a character string describing the macro's value.
 *
 * In addition, each compiler, architecture, language, etc. also defines a specific macro when detected, e.g.
 * @c POC_ARCH_X86_32 is defined if compiling for a 32bit x86 machine architecture. @c POC_ARCH and @c POC_ARCH_X86_32
 * are both set to an (always) predefined @c POC_ARCH_X86_32_ID macro.
 *
 * If no known language, compiler, or endianess could be determined special @c UNKNOWN ids and strings are used as
 * values, e.g. @ POC_OS might be set to @c POC_OS_UNKNOWN_ID and @c POC_OS_STRING is set to @c POC_OS_UNKNOWN_STRING .
 *
 * See @code poc_diagnose_main.c @endcode for an example how to use POC's platform detection macros.
 * 
 *
 * Aside the platform detection macros POC also defines preprocessor symbols to allow portable usage of keywords to:
 * - Align data types automatically on the stack by wrapping the type in @c POC_ALIGN_BEING(<byte-alignment>) and
 *   @c POC_ALIGN_END(<byte-alignment>) macros.
 * - Using @c POC_RESTRICT to enable C99's @c restrict keyword or disable it when compiling for other languages that
 *   don't support it.
 *
 *
 * When adding new platforms (operating system, compiler, architecture, C/C++ standards, etc.) then 
 * first add the following code into every detection branch 
 * @code 
 * #error Untested. Remove error preprocessor directive after having ported and tested the code to the platform. 
 * @endcode .
 * 
 * Only remove the preprocessor error directive after having ported and tested the code on the platform!
 */

#ifndef POC_poc_H
#define POC_poc_H


#include "poc_os.h"
#include "poc_compiler.h"
#include "poc_arch.h"
#include "poc_data_model.h"
#include "poc_endian.h"
#include "poc_lang.h"
#include "poc_posix.h"
#include "poc_portability_macros.h"

// Disable macro undefines via including @code poc_undef.h @endcode and prevent re-defines from accidential
// includes of @code poc_def.h @endcode .
#define POC_HEADER_DISABLE_DEF_UNDEF

#endif // POC_poc_H

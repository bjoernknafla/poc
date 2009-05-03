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
 * Collection of @c POC_OS (prefixed) preprocessor macros to identify the operating system compiling for.
 * 
 * For example if the code is compiled for the Win32 platform,  @c POC_OS_WIN32_ID is stored in @c POC_OS
 * and also the macro @c POC_OS_WIN32 is defined with the previous id value. In this case @c POC_OS_STRING 
 * is set to @c POC_OS_WIN32_STRING .
 *
 * For convenience include this header and don't use @c poc_os_def.h directly. Use the 
 * @code _def.h @endcode and @code _undef.h @endcode files for fine grained control of the parts in the code where 
 * @c POC_ prefixed macros are defined (or undefined) but keep care for yourself that macros aren't redefined.
 * By including the POC headers without the @code _def.h @endcode or @code _undef.h @endcode postfix the defined macros
 * exist throughout the whole compilation unit and can't be undefined by including the corresponding 
 * @code _undef.h @endcode anymore.
 */


/**
 * @def POC_OS
 * Stores a predefined value representing the target operating system compiling for or @c POC_OS_UNKNOWN_ID if the
 * operating system can't be identified (is unknown).
 */

/**
 * @def POC_OS_STRING
 * Stores a C character string describing the identified target operating system.
 */

#ifndef POC_poc_os_H
#define POC_poc_os_H

#include "poc_os_def.h"

/* Disable macro undefines via including @code poc_os_undef.h @endcode and prevent re-defines from accidential
 * includes of @code poc_os_def.h @endcode .
 */
#define POC_OS_HEADER_DISABLE_DEF_UNDEF

#endif /* POC_poc_os_H */

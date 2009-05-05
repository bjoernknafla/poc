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
 * Internal helper macros to concatenate preprocessor values and transform them into strings.
 *
 * For convenience include this header and don't use poc_preprocessor_utility_def.h directly. Use the 
 * @c _def.h and @c _undef.h files for fine grained control of the parts in the code where 
 * @c POC_ prefixed macros are defined (or undefined) but keep care for yourself that macros aren't redefined.
 * By including the POC headers without the @c _def.h  or @c _undef.h postfix the defined macros
 * exist throughout the whole compilation unit and can't be undefined by including the corresponding 
 * @c _undef.h anymore.
 */

#ifndef POC_poc_preprocessor_utilities_H
#define POC_poc_preprocessor_utilities_H


#if defined( POC_CONCAT )
#   error POC_CONCAT macro shouldn't be defined at this point.
#endif

#if defined( POC_DO_CONCAT )
#   error POC_DO_CONCAT macro shouldn't be defined at this point.
#endif


#if defined( POC_DO_CONCAT_2 )
#   error POC_DO_CONCAT_2 macro shouldn't be defined at this point.
#endif

#if defined(POC_STRINGIZE)
#   error POC_STRINGIZE macro shouldn't be defined at this point.
#endif

#if defined(POC_DO_STRINGIZE)
#   error POC_DO_STRINGIZE macro shouldn't be defined at this point.
#endif

#if defined(POC_MATCHES)
#   error POC_MATCHES macro shouldn't be defined at this point.
#endif

#if defined(POC_MATCHES_EXACTLY)
#   error POC_MATCHES_EXACTLY macro shouldn't be defined at this point.
#endif


#include "poc_preprocessor_utilities_def.h"

/* Disable macro undefines via including poc_preprocessor_utilities_undef.h and prevent re-defines from 
 * accidential includes of poc_preprocessor_utilities_def.h .
 */
#define POC_PREPROCESSOR_UTILITIES_HEADER_DISABLE_DEF_UNDEF


#endif /* POC_poc_preprocessor_utilities_H */

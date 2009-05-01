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
 * Preprocessor symbols to detect the target platform the code is compiled for.
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

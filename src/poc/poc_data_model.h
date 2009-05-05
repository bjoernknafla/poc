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
 * Collection of @c POC_DATA_MODEL (prefixed) preprocessor macros to identify the data model of the platform compiling 
 * for.
 *
 * The data model defines the bit-size of primitive language types, for example the size of @c int , @c long , 
 * @c long long , and pointer types.
 * 
 * For example if the code is compiled for Mac OS X,  @c POC_DATA_MODEL_LP64_ID is stored in @c POC_DATA_MODEL
 * and also the macro @c POC_DATA_MODEL_LP64 is defined with the previous id value. In this case @c POC_DATA_MODEL_STRING 
 * is set to @c POC_DATA_MODEL_LP64_STRING . The LP64 data model defines, that @c int is 32bit sized and @c long and
 * pointers are 64bit sized.
 *
 * For convenience include this header and don't use poc_data_model_def.h directly. Use the 
 * @c _def.h and @c _undef.h files for fine grained control of the parts in the code where 
 * @c POC_ prefixed macros are defined (or undefined) but keep care for yourself that macros aren't redefined.
 * By including the POC headers without the @c _def.h or @c _undef.h postfix the defined macros
 * exist throughout the whole compilation unit and can't be undefined by including the corresponding 
 * @c _undef.h anymore.
 */


/**
 * @def POC_DATA_MODEL
 * Stores a predefined value representing the platforms data model or @c POC_DATA_MODEL_UNKNOWN_ID if the
 * data model can't be identified (is unknown).
 */

/**
 * @def POC_DATA_MODEL_STRING
 * Stores a C character string describing the identified data model.
 */

#ifndef POC_poc_data_model_H
#define POC_poc_data_model_H

#include "poc_arch.h"

#include "poc_lang.h"

#include "poc_os.h"

#include "poc_data_model_def.h"

/* Disable macro undefines via including poc_data_model_undef.h and prevent re-defines from accidential
 * includes of poc_data_model_def.h .
 */
#define POC_DATA_MODEL_HEADER_DISABLE_DEF_UNDEF

#endif /* POC_poc_data_model_H */

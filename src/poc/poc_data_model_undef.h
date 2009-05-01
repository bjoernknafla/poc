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
 * Undefines POC programming language macros potentially set by @code poc_data_model_def.h @endcode , see
 * @code poc_data_model.h @endcode and @code poc_data_model_def.h @endcode for more details.
 *
 * @attention This header doesn't have header guards to enable multiple inclusion.
 */

/// Only allow undef of POC data model macros if @code poc_data_model.h @endcode hasn't been included in this 
/// compilation unit.
#if !defined(POC_DATA_MODEL_HEADER_DISABLE_DEF_UNDEF)


#undef POC_DATA_MODEL
#undef POC_DATA_MODEL_STRING

#undef POC_DATA_MODEL_UNKNOWN
#undef POC_DATA_MODEL_UNKNOWN_ID
#undef POC_DATA_MODEL_UNKNOWN_STRING

#undef POC_DATA_MODEL_LP32
#undef POC_DATA_MODEL_LP32_ID
#undef POC_DATA_MODEL_LP32_STRING

#undef POC_DATA_MODEL_ILP32
#undef POC_DATA_MODEL_ILP32_ID
#undef POC_DATA_MODEL_ILP32_STRING

#undef POC_DATA_MODEL_LP64
#undef POC_DATA_MODEL_LP64_ID
#undef POC_DATA_MODEL_LP64_STRING

#undef POC_DATA_MODEL_LLP64
#undef POC_DATA_MODEL_LLP64_ID
#undef POC_DATA_MODEL_LLP64_STRING

#undef POC_DATA_MODEL_ILP64
#undef POC_DATA_MODEL_ILP64_ID
#undef POC_DATA_MODEL_ILP64_STRING

#undef POC_DATA_MODEL_SILP64
#undef POC_DATA_MODEL_SILP64_ID
#undef POC_DATA_MODEL_SILP64_STRING



#endif // !defined(POC_DATA_MODEL_HEADER_DISABLE_DEF_UNDEF)

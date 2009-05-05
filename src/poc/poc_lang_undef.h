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
 * Undefines POC programming language macros potentially set by poc_lang_def.h , see
 * poc_lang.h and poc_lang_def.h for more details.
 *
 * @attention This header doesn't have header guards to enable multiple inclusion.
 */

/* Only allow undef of POC programming language macros if poc_lang.h hasn't been included in this 
 * compilation unit.
 */
#if !defined(POC_LANG_HEADER_DISABLE_DEF_UNDEF)


#undef POC_LANG
#undef POC_LANG_STRING

#undef POC_LANG_UNKNOWN
#undef POC_LANG_UNKNOWN_ID
#undef POC_LANG_UNKNOWN_STRING

#undef POC_LANG_C
#undef POC_LANG_C_STRING

#undef POC_LANG_C_UNKNOWN_ID
#undef POC_LANG_C_UNKNOWN_STRING

#undef POC_LANG_C_C89
#undef POC_LANG_C_C89_ID
#undef POC_LANG_C_C89_STRING
#undef POC_LANG_C_C89_STANDARDIZED_VERSION


#undef POC_LANG_C_C99
#undef POC_LANG_C_C99_ID
#undef POC_LANG_C_C99_STRING
#undef POC_LANG_C_C99_STANDARDIZED_VERSION

#undef POC_LANG_CPP
#undef POC_LANG_CPP_STRING

#undef POC_LANG_CPP_UNKNOWN_ID
#undef POC_LANG_CPP_UNKNOWN_STRING

#undef POC_LANG_CPP_CPP98
#undef POC_LANG_CPP_CPP98_ID
#undef POC_LANG_CPP_CPP98_STRING
#undef POC_LANG_CPP_CPP98_STANDARDIZED_VERSION

#undef POC_LANG_OBJC
#undef POC_LANG_OBJC_ID
#undef POC_LANG_OBJC_STRING

#undef POC_LANG_OBJC_UNKNOWN_ID
#undef POC_LANG_OBJC_UNKNOWN_STRING

#undef POC_LANG_OPENCL
#undef POC_LANG_OPENCL_ID
#undef POC_LANG_OPENCL_STRING
#undef POC_LANG_OPENCL_VERSION

#undef POC_LANG_OPENCL_UNKNOWN_ID
#undef POC_LANG_OPENCL_UNKNOWN_STRING




#undef POC_LANG_C_TYPE_BOOL_SUPPORT
#undef POC_LANG_C_TYPE_LONG_LONG_SUPPORT
#undef POC_LANG_C_TYPE_LONG_DOUBLE_SUPPORT
#undef POC_LANG_C_TYPE_COMPLEX_SUPPORT
#undef POC_LANG_C_TYPE_IMAGINARY_SUPPORT
#undef POC_LANG_C_HEADER_STDBOOL_SUPPORT
#undef POC_LANG_C_HEADER_STDINT_SUPPORT
#undef POC_LANG_C_HEADER_INTTYPES_SUPPORT


#undef POC_LANG_CPP_RTTI_SUPPORT
#undef POC_LANG_CPP_EXCEPTIONS_SUPPORT



#endif /* !defined(POC_LANG_HEADER_DISABLE_DEF_UNDEF) */

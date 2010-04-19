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
 * Undefines portability macros potentially set by poc_primary_types_def.h , see 
 * poc_primary_types.h and poc_primary_types_def.h for more details.
 *
 * @attention This header doesn't have header guards to enable multiple inclusion.
 */



/* Only allow undefines of POC primary types if poc_primary_types.h hasn't been 
 * included in this compilation unit.
 */
#if !defined(POC_PRIMARY_TYPES_HEADER_DISABLE_DEF_UNDEF)


#undef POC_LONG_DOUBLE
#undef POC_LONG_LONG
#undef POC_UNSIGNED_LONG_LONG

#undef POC_BOOL
#undef POC_TRUE
#undef POC_FALSE


#undef POC_BYTE
#undef POC_CHAR
#undef POC_SIGNED_CHAR
#undef POC_UNSIGNED_CHAR
#undef POC_INT8
#undef POC_UINT8
#undef POC_INT16
#undef POC_UINT16
#undef POC_INT32
#undef POC_UINT32
#undef POC_INT64
#undef POC_UINT64
#undef POC_INTPTR_T
#undef POC_UINTPTR_T
#undef POC_PTRDIFF_T
#undef POC_SIZE_T
#undef POC_FLOAT32
#undef POC_FLOAT64

#undef POC_INT8_C
#undef POC_UINT8_C
#undef POC_INT16_C
#undef POC_UINT16_C
#undef POC_INT32_C
#undef POC_UINT32_C
#undef POC_INT64_C
#undef POC_UINT64_C

#undef POC_FLOAT32_C
#undef POC_FLOAT64_C


#endif /* !defined(POC_PRIMARY_TYPES_HEADER_DISABLE_DEF_UNDEF) */

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
 * C++ compile-time checks if the defined primary type sizes are correct.
 *
 * More tests would be possible with C++0x type traits.
 */

#ifndef POC_poc_primary_types_cpp_compile_time_checks_H
#define POC_poc_primary_types_cpp_compile_time_checks_H

#if defined(__cplusplus)

/*
 * Include std::ptrdiff_t, std::size_t
 */
#include <cstddef>

/* 
 * Include CHAR_BIT
 */
#include <climits>

/*
 * Will be undefined at the end of the file.
 */
#include "poc_primary_types_def.h"

/* 
 * Include POC_STATIC_ASSERT
 *
 * Will be undefined at the end of the file.
 */
#include "poc_static_assert_def.h"


namespace {

#if defined(POC_BOOL)
        POC_STATIC_ASSERT(sizeof(POC_BOOL) == sizeof(bool), "Size of POC_BOOL must be the same as the size of bool.");
#endif
    
#if defined(POC_LONG_LONG)
    POC_STATIC_ASSERT(sizeof(POC_LONG_LONG) == sizeof(long long), "Size of POC_LONG_LONG must be the same as the size of long long.");
#endif
#if defined(POC_UNSIGNED_LONG_LONG)
    POC_STATIC_ASSERT(sizeof(POC_UNSIGNED_LONG_LONG) == sizeof(unsigned long long), "Size of POC_UNSIGNED_LONG_LONG must be the same as the size of unsigned long long.");
#endif
    
#if defined(POC_LONG_DOUBLE)
    POC_STATIC_ASSERT(sizeof(POC_LONG_DOUBLE) == sizeof(long double), "Size of POC_LONG_DOUBLE must be the same as the size of long double.");
#endif
    
#if defined(POC_BYTE)
    POC_STATIC_ASSERT(sizeof(POC_BYTE) * CHAR_BIT == 8, "Size of POC_BYTE must be 8 bits.");
#endif
    
#if defined(POC_INT8)
    POC_STATIC_ASSERT(sizeof(POC_INT8) * CHAR_BIT == 8, "Size of POC_INT8 must be 8 bits.");
#endif
#if defined(POC_UINT8)
    POC_STATIC_ASSERT(sizeof(POC_UINT8) * CHAR_BIT == 8, "Size of POC_UINT8 must be 8 bits.");
#endif 
    
    
#if defined(POC_INT16)
    POC_STATIC_ASSERT(sizeof(POC_INT16) * CHAR_BIT == 16, "Size of POC_INT16 must be 16 bits.");
#endif
#if defined(POC_UINT16)
    POC_STATIC_ASSERT(sizeof(POC_UINT16) * CHAR_BIT == 16, "Size of POC_UINT16 must be 16 bits.");
#endif
    
#if defined(POC_INT32)
    POC_STATIC_ASSERT(sizeof(POC_INT32) * CHAR_BIT == 32, "Size of POC_INT32 must be 32 bits.");
#endif
#if defined(POC_UINT32)
    POC_STATIC_ASSERT(sizeof(POC_UINT32) * CHAR_BIT == 32, "Size of POC_UINT32 must be 32 bits.");
#endif
    
#if defined(POC_INT64)
    POC_STATIC_ASSERT(sizeof(POC_INT64) * CHAR_BIT == 64, "Size of POC_INT64 must be 64 bits.");
#endif
#if defined(POC_UINT64)
    POC_STATIC_ASSERT(sizeof(POC_UINT64) * CHAR_BIT == 64, "Size of POC_UINT64 must be 64 bits.");
#endif
    
#if defined(POC_INTMAX)
#   if defined(POC_INT64)
    POC_STATIC_ASSERT(sizeof(POC_INT64) == sizeof(POC_INTMAX), "Size of POC_INTMAX must be equal to the greatest integral type.");
#   elif defined(POC_INT32)
    POC_STATIC_ASSERT(sizeof(POC_INT32) == sizeof(POC_INTMAX), "Size of POC_INTMAX must be equal to the greatest integral type.");
#   else
#       error Currently only 64bit or 32bit POC_INTMAX types are supported.
#   endif
#endif
#if defined(POC_UINTMAX)
#   if defined(POC_UINT64)
    POC_STATIC_ASSERT(sizeof(POC_UINT64) == sizeof(POC_UINTMAX), "Size of POC_UINTMAX must be equal to the greatest integral type.");
#   elif defined(POC_INT32)
    POC_STATIC_ASSERT(sizeof(POC_UINT32) == sizeof(POC_UINTMAX), "Size of POC_UINTMAX must be equal to the greatest integral type.");
#   else
#       error Currently only 64bit or 32bit POC_UINTMAX types are supported.
#   endif
#endif

#if defined(POC_INTPTR_T)
    POC_STATIC_ASSERT(sizeof(POC_INTPTR_T) == sizeof(void*), "Size of POC_INTPTR_T must be the same as pointer size.");
#endif
#if defined(POC_UINTPTR_T)
    POC_STATIC_ASSERT(sizeof(POC_UINTPTR_T) == sizeof(void*), "Size of POC_UINTPTR_T must be the same as pointer size.");
#endif
    
#if defined(POC_FLOAT32)
    POC_STATIC_ASSERT(sizeof(POC_FLOAT32) * CHAR_BIT == 32, "Size of POC_FLOAT32 must be 32 bits.");
#endif
#if defined(POC_FLOAT64)
   POC_STATIC_ASSERT(sizeof(POC_FLOAT64) * CHAR_BIT == 64, "Size of POC_FLOAT64 must be 64 bits.");    
#endif
    
#if defined(POC_PTRDIFF_T)
    POC_STATIC_ASSERT(sizeof(POC_PTRDIFF_T) == sizeof(std::ptrdiff_t), "Size of POC_PTRDIFF_T must be the same as the size of std::ptrdiff_t.");
#endif    
#if defined(POC_SIZE_T)
    POC_STATIC_ASSERT(sizeof(POC_SIZE_T) == sizeof(std::size_t), "Size of POC_SIZE_T must be the same as the size of std::size_t.");
#endif
    

} // anonymous namespace

// Undefine static assertion macros.
#include "poc_static_assert_undef.h"

// Undefine POC data model, os, arch, and lang macros.
#include "poc_primary_types_lang_compiler_data_model_undef.h"

#else
#   error C++ header - don't use with pure C.
#endif /* defined(__cplusplus) */



#endif /* POC_poc_primary_types_cpp_compile_time_checks_H */

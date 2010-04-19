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
 * C++ compile-time checks if the detected data model is correct - if the
 * primary types have the bit-size defined by the detected data model.
 */

#ifndef POC_poc_data_model_cpp_compile_time_checks_H
#define POC_poc_data_model_cpp_compile_time_checks_H

#if defined(__cplusplus)

/* 
 * Include CHAR_BIT
 */
#include <climits>

/*
 * Include POC_DATA_MODEL_
 *
 * Will be undefined at the end of the file.
 */
#include "poc_data_model_def.h"

/* 
 * Include POC_LANG preprocessor symbols
 */
#include "poc_lang_def.h"

/* 
 * Include POC_STATIC_ASSERT
 *
 * Will be undefined at the end of the file.
 */
#include "poc_static_assert_def.h"


namespace {
    
/*******************************************************************************
 * Compile time check of data model correctness
 ******************************************************************************/
    
#if defined(POC_DATA_MODEL_LP32)
    POC_STATIC_ASSERT( sizeof( char ) * CHAR_BIT == 8, "The LP32 data model requires char to be 8 bit" );
    POC_STATIC_ASSERT( sizeof( short ) * CHAR_BIT == 16,"The LP32 data model requires short to be 16 bit" );
    POC_STATIC_ASSERT( sizeof( int ) * CHAR_BIT == 16, "The LP32 data model requires int to be 16 bit" );
    POC_STATIC_ASSERT( sizeof( long ) * CHAR_BIT == 32, "The LP32 data model requires long to be 32 bit");
#   if defined(POC_LANG_CPP_TYPE_LONG_LONG_SUPPORT)
    POC_STATIC_ASSERT( sizeof( long long ) * CHAR_BIT == 64, "The LP32 data model requires long long to be 64 bit" );
#   endif
    POC_STATIC_ASSERT( sizeof( void* ) * CHAR_BIT == 32, "The LP32 data model requires pointers to be 32 bit" );
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif
    
    
#if defined(POC_DATA_MODEL_ILP32)
    POC_STATIC_ASSERT( sizeof( char ) * CHAR_BIT == 8, "The ILP32 data model requires char to be 8 bit" );
    POC_STATIC_ASSERT( sizeof( short ) * CHAR_BIT == 16, "The ILP32 data model requires short to be 16 bit" );
    POC_STATIC_ASSERT( sizeof( int ) * CHAR_BIT == 32, "The ILP32 data model requires int to be 32 bit" );
    POC_STATIC_ASSERT( sizeof( long ) * CHAR_BIT == 32, "The ILP32 data model requires long to be 32 bit" );
#   if defined(POC_LANG_CPP_TYPE_LONG_LONG_SUPPORT)
    POC_STATIC_ASSERT( sizeof( long long ) * CHAR_BIT == 64, "The ILP32 data model requires long long to be 64 bit" );
#   endif
    POC_STATIC_ASSERT( sizeof( void* ) * CHAR_BIT == 32, "The ILP32 data model requires pointers to be 32 bit" );                        
#endif
    
    
#if defined(POC_DATA_MODEL_LP64)
    POC_STATIC_ASSERT( sizeof( char ) * CHAR_BIT == 8, "The LP64 data model requires char to be 8 bit" );
    POC_STATIC_ASSERT( sizeof( short ) * CHAR_BIT == 16, "The LP64 data model requires short to be 16 bit" );
    POC_STATIC_ASSERT( sizeof( int ) * CHAR_BIT == 32, "The LP64 data model requires int to be 32 bit" );
    POC_STATIC_ASSERT( sizeof( long ) * CHAR_BIT == 64, "The LP64 data model requires long to be 64 bit" );
#   if defined(POC_LANG_CPP_TYPE_LONG_LONG_SUPPORT)
    POC_STATIC_ASSERT( sizeof( long long ) * CHAR_BIT == 64, "The LP64 data model requires long long to be 64 bit" );
#   endif
    POC_STATIC_ASSERT( sizeof( void* ) * CHAR_BIT == 64, "The LP64 data model requires pointers to be 64 bit" );
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif
    
#if defined(POC_DATA_MODEL_LLP64)
    POC_STATIC_ASSERT( sizeof( char ) * CHAR_BIT == 8, "The LLP64 data model requires char to be 8 bit" );
    POC_STATIC_ASSERT( sizeof( short ) * CHAR_BIT == 16, "The LLP64 data model requires short to be 16 bit" );
    POC_STATIC_ASSERT( sizeof( int ) * CHAR_BIT == 32, "The LLP64 data model requires int to be 32 bit" );
    POC_STATIC_ASSERT( sizeof( long ) * CHAR_BIT == 32, "The LLP64 data model requires long to be 32 bit" );
#   if defined(POC_LANG_CPP_TYPE_LONG_LONG_SUPPORT)
    POC_STATIC_ASSERT( sizeof( long long ) * CHAR_BIT == 64, "The LLP64 data model requires lonb long to be 64 bit" );
#   endif
    POC_STATIC_ASSERT( sizeof( void* ) * CHAR_BIT == 64, "The LLP64 data model requires pointers to be 64 bit" );                        
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif
    
#if defined(POC_DATA_MODEL_ILP64)
    POC_STATIC_ASSERT( sizeof( char ) * CHAR_BIT == 8, "The ILP64 data model requires char to be 8 bit" );
    POC_STATIC_ASSERT( sizeof( short ) * CHAR_BIT == 16, "The ILP64 data model requires short to be 16 bit" );
    POC_STATIC_ASSERT( sizeof( _int32 ) * CHAR_BIT == 32, "The ILP64 data model requires _int32 to be 32 bit" );
    POC_STATIC_ASSERT( sizeof( int ) * CHAR_BIT == 64, "The ILP64 data model requires int to be 64 bit" );
    POC_STATIC_ASSERT( sizeof( long ) * CHAR_BIT == 64, "The ILP64 data model requires long to be 64 bit" );
#   if defined(POC_LANG_CPP_TYPE_LONG_LONG_SUPPORT)
    POC_STATIC_ASSERT( sizeof( long long ) * CHAR_BIT == 64, "The ILP64 data model requires long long to be 64 bit" );
#   endif
    POC_STATIC_ASSERT( sizeof( void* ) * CHAR_BIT == 64, "The ILP64 data model requires pointers to be 64 bit" );                        
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif
    
    
#if defined(POC_DATA_MODEL_SILP64)
    POC_STATIC_ASSERT( sizeof( char ) * CHAR_BIT == 8, "The SILP64 data model requires char to be 8 bit" );
    POC_STATIC_ASSERT( sizeof( short ) * CHAR_BIT == 64, "The SILP64 data model requires short to be 64 bit" );
    POC_STATIC_ASSERT( sizeof( int ) * CHAR_BIT == 64, "The SILP64 data model requires int to be 64 bit" );
    POC_STATIC_ASSERT( sizeof( long ) * CHAR_BIT == 64, "The SILP64 data model requires long to be 64 bit" );
#   if defined(POC_LANG_CPP_TYPE_LONG_LONG_SUPPORT)
    POC_STATIC_ASSERT( sizeof( long long ) * CHAR_BIT == 64, "The SILP64 data model requires long long to be 64 bit" );
#   endif
    POC_STATIC_ASSERT( sizeof( void* ) * CHAR_BIT == 64, "The SILP64 data model requires pointers to be 64 bit" );                        
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif
    
    
    
    
    
} // anonymous namespace

// Undefine static assertion macros.
#include "poc_static_assert_undef.h"

// Undefine poc lang macros
#include "poc_lang_undef.h"

// Undefine POC data model, os, arch, and lang macros.
#include "poc_data_model_os_arch_lang_undef.h"

#else
#   error C++ header - don't use with pure C.
#endif /* defined(__cplusplus) */



#endif /* POC_poc_data_model_cpp_compile_time_checks_H */

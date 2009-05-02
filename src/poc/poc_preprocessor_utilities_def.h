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
 * See @code poc_preprocessor_utilities.h @endcode for details.
 *
 * @attention This header doesn't have header guards to allow successive inclusion of it and its sibling 
 *            @code poc_preprocessor_utilities_undef.h @endcode . If header guards are wanted or needed use 
 *            @code poc_preprocessor_utilities.h @endcode instead.
 */

// Only allow definition of POC preprocessor utilities macros if @code poc_preprocessor_utilities.h @endcode 
// hasn't been included in this compilation unit.
#if !defined(POC_PREPROCESSOR_UTILITIES_HEADER_DISABLE_DEF_UNDEF)


/// TODO: @todo Check all strings that they are at max 32 characters long.
/// Maximum length of POC strings defined.
#define POC_STRINGS_MAX_LENGTH 32

/// @name Concatenation macros
///
/// Inspired by Boost's @c suffix.hpp preprocessor macros.
/// @c POC_CONCAT concatenates the values of its paremeters to one new preprocessor symbol.
/// The two-times indirection by calling @c POC_DO_CONCAT and @c POC_DO_CONCAT_2
/// enables the arguments to be preprocessor expanded before concatenating them.
///
///@{
#define POC_CONCAT( X, Y ) POC_DO_CONCAT( X, Y )
#define POC_DO_CONCAT( X, Y ) POC_DO_CONCAT_2( X, Y )
#define POC_DO_CONCAT_2( X , Y ) X ## Y
///@}

/// @name Transfer macro-name into string
///
/// Extracts the value of @a Val and converts it into a string.
///@{
#define POC_STRINGIZE( Val ) POC_DO_STRINGIZE( Val )
#define POC_DO_STRINGIZE( Val ) #Val
///@}


#endif // !defined(POC_PREPROCESSOR_UTILITIES_HEADER_DISABLE_DEF_UNDEF)

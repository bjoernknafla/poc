







// Include POC_OS preprocessor symbols
#include "poc_os_def.h"

// Include POC_ARCH preprocessor symbols
#include "poc_arch_def.h"

// Include POC_LANG preprocessor symbols
#include "poc_lang_def.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Predefined data model ids for 32 and 64 bit environments.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///@{
#define POC_DATA_MODEL_UNKNOWN_ID 0
// #define POC_DATA_MODEL_LP32_ID 1 // No detection implemented.
#define POC_DATA_MODEL_ILP32_ID 2
#define POC_DATA_MODEL_LP64_ID 4
#define POC_DATA_MODEL_LLP64_ID 8
// #define POC_DATA_MODEL_ILP64_ID 16 // No detection implemented.
// #define POC_DATA_MODEL_SILP64_ID 32 // No detection implemented.
///@}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Predefined data model strings for 32 and 64 bit environments.
///
/// See:
/// - http://www.ddj.com/hpc-high-performance-computing/184401972
/// - http://en.wikipedia.org/wiki/64-bit
/// - http://en.wikipedia.org/wiki/32-bit
/// - http://archive.opengroup.org/public/tech/aspen/lp64_wp.htm
///
/// Data models:
/// - LP32: int type is 16 bit long and pointer types are 32 bit. Unsupported.
/// - ILP32: int, long, and pointer data types are 32 bit.
/// - LP64: long and pointer types are 64bit, the int type is 32 bit.
/// - LLP64: pointer types are 64bit, the int type is 32 bit, long long is a 64 bit type.
/// - ILP64: int, long, and pointer types are 64 bit. Unsupported.
/// - SILP64: short, int, long, and pointer types are 64 bit. Unsupported.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///@{
#define POC_DATA_MODEL_UNKNOWN_STRING "Unknown data model"
// #define POC_DATA_MODEL_LP32_STRING "LP32" // No detection implemented.
#define POC_DATA_MODEL_ILP32_STRING "ILP32"
#define POC_DATA_MODEL_LP64_STRING "LP64"
#define POC_DATA_MODEL_LLP64_STRING "LLP64"
// #define POC_DATA_MODEL_ILP64_STRING "ILP64" // No detection implemented.
// #define POC_DATA_MODEL_SILP64_STRING "SILP64" // No detection implemented.
///@}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Detect data model.
//
// To detect the data model used by the target platform first the target operating system and then the architecture are
// analyzed.
//
// @todo Implement data model detection for Linux, Unix, etc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// 32bit Mac OS X uses the ILP32 data model, 64bit Mac OS X uses the LP64 data model.
//@{
#if defined(POC_OS_MACOSX)
#   if defined(_LP64) || defined(__LP64__) 
#       define POC_DATA_MODEL_LP64 POC_DATA_MODEL_LP64_ID
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   else
#       if defined(POC_ARCH_X86_64)
#           error On 64bit Mac OS X the _LP64 or __LP64__ symbol should be set.
#       endif
#       define POC_DATA_MODEL_ILP32 POC_DATA_MODEL_ILP32_ID
#   endif
#endif
//@}

// 32bit Linux uses the ILP32 data model, 64bit Linux uses the LP64 data model.
// @todo Check facts.
#if defined(POC_OS_LINUX)
#   if defined(_LP64) || defined(__LP64__) || defined(__lp64)
#       define POC_DATA_MODEL_LP64 POC_DATA_MODEL_LP64_ID
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   else
#       if defined(POC_ARCH_X86_64)
#           error On 64bit Linux the _LP64 or __LP64__ symbol should be set.
#       endif
#       define POC_DATA_MODEL_ILP32 POC_DATA_MODEL_ILP32_ID
#   endif
#endif


// Win32 uses the ILP32 data model
#if defined(POC_OS_WIN32)
#   define POC_DATA_MODEL_ILP32 POC_DATA_MODEL_ILP32_ID
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif


// Win64 uses the LLP64 data model
#if defined(POC_OS_WIN64)
#   define POC_DATA_MODEL_LLP64 POC_DATA_MODEL_LLP64_ID
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Detect @c POC_DATA_MODEL_ID and @c POC_DATA_MODEL_STRING
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(POC_DATA_MODEL_ILP32)
#   define POC_DATA_MODEL_ID POC_DATA_MODEL_ILP32_ID
#   define POC_DATA_MODEL_STRING POC_DATA_MODEL_ILP32_STRING
#endif

#if defined(POC_DATA_MODEL_LP64)
#   define POC_DATA_MODEL_ID POC_DATA_MODEL_LP64_ID
#   define POC_DATA_MODEL_STRING POC_DATA_MODEL_LP64_STRING
#endif

#if defined(POC_DATA_MODEL_LLP64)
#   define POC_DATA_MODEL_ID POC_DATA_MODEL_LLP64_ID
#   define POC_DATA_MODEL_STRING POC_DATA_MODEL_LLP64_STRING
#endif


// No known data model detected.
#if !defined(POC_DATA_MODEL_STRING) || !defined(POC_DATA_MODEL_ID)
#   define POC_DATA_MODEL_ID POC_DATA_MODEL_UNKNOWN_ID
#   define POC_DATA_MODEL_STRING POC_DATA_MODEL_UNKNOWN_STRING
#   error Unknown data model.
#endif



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Correctnes checks and tests
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Exactly one data model must have been choosen - xor tests to find possible error.
#if defined(POC_DATA_MODEL_LP32) \
&& (defined(POC_DATA_MODEL_ILP32) \
|| defined(POC_DATA_MODEL_LP64) \
|| defined(POC_DATA_MODEL_LLP64) \
|| defined(POC_DATA_MODEL_ILP64) \
|| defined(POC_DATA_MODEL_SILP64) )
#   error Exactly one data model must be selected.
#elif defined(POC_DATA_MODEL_ILP32) \
&& (defined(POC_DATA_MODEL_LP32) \
|| defined(POC_DATA_MODEL_LP64) \
|| defined(POC_DATA_MODEL_LLP64) \
|| defined(POC_DATA_MODEL_ILP64) \
|| defined(POC_DATA_MODEL_SILP64) )
#   error Exactly one data model must be selected.
#elif defined(POC_DATA_MODEL_LP64) \
&& (defined(POC_DATA_MODEL_LP32) \
|| defined(POC_DATA_MODEL_ILP32) \
|| defined(POC_DATA_MODEL_LLP64) \
|| defined(POC_DATA_MODEL_ILP64) \
|| defined(POC_DATA_MODEL_SILP64) )
#   error Exactly one data model must be selected.
#elif defined(POC_DATA_MODEL_LLP64) \
&& (defined(POC_DATA_MODEL_LP32) \
|| defined(POC_DATA_MODEL_ILP32) \
|| defined(POC_DATA_MODEL_LP64) \
|| defined(POC_DATA_MODEL_ILP64) \
|| defined(POC_DATA_MODEL_SILP64) )
#   error Exactly one data model must be selected.
#elif defined(POC_DATA_MODEL_ILP64) \
&& (defined(POC_DATA_MODEL_LP32) \
|| defined(POC_DATA_MODEL_ILP32) \
|| defined(POC_DATA_MODEL_LP64) \
|| defined(POC_DATA_MODEL_LLP64) \
|| defined(POC_DATA_MODEL_SILP64) )
#   error Exactly one data model must be selected.
#elif defined(POC_DATA_MODEL_SILP64) \
&& (defined(POC_DATA_MODEL_LP32) \
|| defined(POC_DATA_MODEL_ILP32) \
|| defined(POC_DATA_MODEL_LP64) \
|| defined(POC_DATA_MODEL_LLP64) \
|| defined(POC_DATA_MODEL_ILP64) )
#   error Exactly one data model must be selected.
#endif





#if defined(__cplusplus)

/// @TODO: Is there a way to prevent reliably (if @c climits is included by a header including this header) that any 
///        symbols declared in @c climits leak into this header?
// Include CHAR_BIT
#include <climits>

// Include POC_STATIC_ASSERT
#include "poc_static_assert_def.h"


namespace {
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Compile time check of data model correctness
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if defined(POC_DATA_MODEL_LP32)
    POC_STATIC_ASSERT( sizeof( char ) * CHAR_BIT == 8, "The LP32 data model requires char to be 8 bit" );
    POC_STATIC_ASSERT( sizeof( short ) * CHAR_BIT == 16,"The LP32 data model requires short to be 16 bit" );
    POC_STATIC_ASSERT( sizeof( int ) * CHAR_BIT == 16, "The LP32 data model requires int to be 16 bit" );
    POC_STATIC_ASSERT( sizeof( long ) * CHAR_BIT == 32, "The LP32 data model requires long to be 32 bit");
#   if defined(POC_LANG_TYPE_LONG_LONG_SUPPORTED)
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
#   if defined(POC_LANG_TYPE_LONG_LONG_SUPPORTED)
    POC_STATIC_ASSERT( sizeof( long long ) * CHAR_BIT == 64, "The ILP32 data model requires long long to be 64 bit" );
#   endif
    POC_STATIC_ASSERT( sizeof( void* ) * CHAR_BIT == 32, "The ILP32 data model requires pointers to be 32 bit" );                        
#endif
    
    
#if defined(POC_DATA_MODEL_LP64)
    POC_STATIC_ASSERT( sizeof( char ) * CHAR_BIT == 8, "The LP64 data model requires char to be 8 bit" );
    POC_STATIC_ASSERT( sizeof( short ) * CHAR_BIT == 16, "The LP64 data model requires short to be 16 bit" );
    POC_STATIC_ASSERT( sizeof( int ) * CHAR_BIT == 32, "The LP64 data model requires int to be 32 bit" );
    POC_STATIC_ASSERT( sizeof( long ) * CHAR_BIT == 64, "The LP64 data model requires long to be 64 bit" );
#   if defined(POC_LANG_TYPE_LONG_LONG_SUPPORTED)
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
#   if defined(POC_LANG_TYPE_LONG_LONG_SUPPORTED)
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
#   if defined(POC_LANG_TYPE_LONG_LONG_SUPPORTED)
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
#   if defined(POC_LANG_TYPE_LONG_LONG_SUPPORTED)
    POC_STATIC_ASSERT( sizeof( long long ) * CHAR_BIT == 64, "The SILP64 data model requires long long to be 64 bit" );
#   endif
    POC_STATIC_ASSERT( sizeof( void* ) * CHAR_BIT == 64, "The SILP64 data model requires pointers to be 64 bit" );                        
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif
    
    
    
    
    
} // anonymous namespace

#include "poc_static_assert_undef.h"

#endif // defined(__cplusplus)


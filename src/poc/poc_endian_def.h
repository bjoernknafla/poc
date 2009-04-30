


// Include POC_ARCH prefixed preprocessor symbols
#include "poc_arch_def.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Endianness ids
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///@{
#define POC_ENDIAN_UNKNOWN_ID 0
#define POC_ENDIAN_LITTLE_ID 1
#define POC_ENDIAN_BIG_ID 2
///@}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Endianness strings
///
/// See http://en.wikipedia.org/wiki/Endianness
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///@{
#define POC_ENDIAN_UNKNOWN_STRING "Unknown endian"
#define POC_ENDIAN_LITTLE_STRING "Little endian"
#define POC_ENDIAN_BIG_STRING "Big endian"
///@}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Detect endianness.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Detect little endianness
// @todo Add detection of big endianness.
#if defined(__LITTLE_ENDIAN__) || defined (__ENDIAN_LITTLE__) || defined(POC_ARCH_X86) || defined(INIGMA_ARCH_X86_32) || defined(POC_ARCH_X86_64)
#   define POC_ENDIAN_LITTLE POC_ENDIAN_LITTLE_ID
#endif

#if defined(__BIG_ENDIAN__) || (defined(__OPENCL_VERSION__) && !defined(__ENDIAN_LITTLE__))
#   define POC_ENDIAN_BIG POC_ENDIAN_BIG_ID
#endif


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Detect @c POC_ENDIAN_ID and @c POC_ENDIAN_STRING
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(POC_ENDIAN_LITTLE)
#   define POC_ENDIAN POC_ENDIAN_LITTLE_ID
#   define POC_ENDIAN_STRING POC_ENDIAN_LITTLE_STRING
#endif

#if defined(POC_ENDIAN_BIG)
#   define POC_ENDIAN POC_ENDIAN_BIG_ID
#   define POC_ENDIAN_STRING POC_ENDIAN_BIG_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif


// Endianess unknown
#if !defined(POC_ENDIAN) || !defined(POC_ENDIAN_STRING)
#   define POC_ENDIAN_UNKNOWN POC_ENDIAN_UNKNOWN_ID
#   define POC_ENDIAN POC_ENDIAN_UNKNOWN_ID
#   define POC_ENDIAN_STRING POC_ENDIAN_UNKNOWN_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif


// Detect erroreneous declaration of little and big endianness at the same time
// @todo How to handle bi-endian architectures?
#if defined(POC_ENDIAN_LITTLE) && (defined(POC_ENDIAN_BIG) || defined(POC_ENDIAN_UNKNOWN))
#   error Little and big endianness mustn't be active at the same time.
#   error Endianess must be little or big.
#elif defined(POC_ENDIAN_BIG) && (defined(POC_ENDIAN_LITTLE) || defined(POC_ENDIAN_UNKNOWN))
#   error Little and big endianness mustn't be active at the same time.
#   error Endianess must be little or big.
#elif defined(POC_ENDIAN_UNKNOWN) && (defined(POC_ENDIAN_BIG) || defined(POC_ENDIAN_LITTLE))
#   error Little and big endianness mustn't be active at the same time.
#   error Endianess must be little or big.
#endif

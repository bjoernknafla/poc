/**
 * @file
 *
 * Preprocessor macros to determine the compile-time target.
 *
 * @attention This header doesn't have header guards to allow successive inclusion of it and its sibling 
 *            @c poc_os_undef.h. If header guards are wanted or needed use @c poc.h or @c poc_os.h instead.
 */


#if !defined(POC_OS_HEADER_DISABLE_DEF_UNDEF)


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Predefined operating system ids
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///@{
#define POC_OS_UNKNOWN_ID 0
#define POC_OS_UNIX_ID 1
#define POC_OS_MACOSX_ID 2
#define POC_OS_LINUX_ID 4
#define POC_OS_WIN32_ID 8
#define POC_OS_WIN64_ID 16
///@}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Predefined operating system strings
/// See http://predef.sourceforge.net/index.php for macros defined by language standards, compilers, libraries, etc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///@{
#define POC_OS_UNKNOWN_STRING "Unknown operating system"
#define POC_OS_UNIX_STRING "Unix (generic)"
#define POC_OS_MACOSX_STRING "Mac OS X"
#define POC_OS_LINUX_STRING "Linux"
#define POC_OS_WIN32_STRING "Win32"
#define POC_OS_WIN64_STRING "Win64"
///@}



// If @c POC_OS_SET_BY_HAND is defined no automatic operating system detection should take place.
#if !defined(POC_OS_DISABLE_AUTODETECT) && !defined(POC_DISABLE_AUTODETECT)


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Determine operating system
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Detect Mac OS X
#if defined(__APPLE__) && defined(__MACH__)
#   define POC_OS_MACOSX POC_OS_MACOSX_ID
#endif

// Detect Linux
#if defined(linux) || defined(__linux) || defined(__linux__)
#   define POC_OS_LINUX POC_OS_LINUX_ID
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

// Detect generic Unix
#if defined(__unix__)
#   define POC_OS_UNIX POC_OS_UNIX_ID
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

// Detect Win32
#if defined(_WIN32) || defined(__WIN32__)
#   define POC_OS_WIN POC_OS_WIN32_ID
#   define POC_OS_WIN32 POC_OS_WIN32_ID
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

// Detect Win64
// MSVC defined _WIN32 even if _WIN64 is defined - however to make it clear which OS is used only @c POC_OS_WIN32 or
// alternatively @c POC_OS_WIN64 is defined, but not both together.
#if defined(_WIN64)
#   define POC_OS_WIN POC_OS_WIN64_ID
#   define POC_OS_WIN64 POC_OS_WIN64_ID
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Determine @c POC_OS and @c POC_OS_STRING
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if defined(POC_OS_UNIX)
#   define POC_OS POC_OS_UNIX_ID
#   define POC_OS_STRING POC_OS_UNIX_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(POC_OS_MACOSX)
#   define POC_OS POC_OS_MACOSX_ID
#   define POC_OS_STRING POC_OS_MACOSX_STRING
#endif

#if defined(POC_OS_LINUX)
#   define POC_OS POC_OS_LINUX_ID
#   define POC_OS_STRING POC_OS_LINUX_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif


#if defined(POC_OS_WIN32)
#   define POC_OS POC_OS_WIN32_ID
#   define POC_OS_STRING POC_OS_WIN32_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(POC_OS_WIN64)
#   define POC_OS POC_OS_WIN64_ID
#   define POC_OS_STRING POC_OS_WIN64_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif


#endif // !defined(POC_OS_DISABLE_AUTODETECT) && !defined(POC_DISABLE_AUTODETECT)



// No known operating system detected
#if !defined(POC_OS)
#   define POC_OS_UNKNOWN POC_OS_UNKNOWN_ID
#   define POC_OS POC_OS_UNKNOWN_ID
#   error Unknown operating system.
#endif

#if !defined(POC_OS_STRING)
#   define POC_OS_STRING POC_OS_UNKNOWN_STRING
#   error Unknown operating system string.
#endif


// Exaclty one operation system must have been chosen - xor test to find possible error.
#if defined(POC_OS_UNIX) && \
(defined(POC_OS_MACOSX) || \
defined(POC_OS_LINUX) || \
defined(POC_OS_WIN32) || \
defined(POC_OS_WIN64) || \
defined(POC_OS_UNKNOWN))
#   error Exactly one operating system must be selected.
#elif defined(POC_OS_MACOSX) && \
(defined(POC_OS_UNIX) || \
defined(POC_OS_LINUX) || \
defined(POC_OS_WIN32) || \
defined(POC_OS_WIN64) || \
defined(POC_OS_UNKNOWN))
#   error Exactly one operating system must be selected.
#elif defined(POC_OS_LINUX) && \
(defined(POC_OS_MACOSX) || \
defined(POC_OS_UNIX) || \
defined(POC_OS_WIN32) || \
defined(POC_OS_WIN64) || \
defined(POC_OS_UNKNOWN))
#   error Exactly one operating system must be selected.
#elif defined(POC_OS_WIN32) && \
(defined(POC_OS_MACOSX) || \
defined(POC_OS_LINUX) || \
defined(POC_OS_UNIX) || \
defined(POC_OS_WIN64) || \
defined(POC_OS_UNKNOWN))
#   error Exactly one operating system must be selected.
#elif defined(POC_OS_WIN64) && \
(defined(POC_OS_MACOSX) || \
defined(POC_OS_LINUX) || \
defined(POC_OS_WIN32) || \
defined(POC_OS_UNIX) || \
defined(POC_OS_UNKNOWN))
#   error Exactly one operating system must be selected.
#elif defined(POC_OS_UNKNOWN) && \
(defined(POC_OS_MACOSX) || \
defined(POC_OS_LINUX) || \
defined(POC_OS_WIN32) || \
defined(POC_OS_WIN64) || \
defined(POC_OS_UNIX))
#   error Exactly one operating system must be selected.
#endif



#endif // !defined(POC_OS_HEADER_DISABLE_DEF_UNDEF)


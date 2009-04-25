/**
 * @file
 *
 * Preprocessor macros to determine the compile-time target.
 *
 * @attention This header doesn't have header guards to allow successive inclusion of it and its sibling 
 *            @c poc_os_undef.h. If header guards are wanted or needed use @c poc.h or @c poc_os.h instead.
 */


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Predefined operating system ids
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///@{
#define POC_OS_UNKNOWN_ID 0
#define POC_OS_UNIX_ID 1
#define POC_OS_MACOSX_ID 2
#define POC_OS_LINUX_ID 4
#define POC_OS_WIN_ID 8
#define POC_OS_WIN32_ID 16
#define POC_OS_WIN64_ID 32
///@}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Known operating system strings
/// See http://predef.sourceforge.net/index.php for macros defined by language standards, compilers, libraries, etc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///@{
#define POC_OS_UNKNOWN_STRING "Unknown operating system"
#define POC_OS_UNIX_STRING "Unix (generic)"
#define POC_OS_MACOSX_STRING "Mac OS X"
#define POC_OS_LINUX_STRING "Linux"
#define POC_OS_WIN_STRING "Windows"
#define POC_OS_WIN32_STRING "Win32"
#define POC_OS_WIN64_STRING "Win64"
///@}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Determine operating system
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// If @c POC_OS_SET_BY_HAND is defined no automatic operating system detection should take place.
#if !defined(POC_OS_SET_BY_HAND)

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
#   define POC_OS_WIN POC_OS_WIN_ID
#   define POC_OS_WIN32 POC_OS_WIN32_ID
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

// Detect Win64
#if defined(_Win64)
#   define POC_OS_WIN POC_OS_WIN_ID
#   define POC_OS_WIN64 POC_OS_WIN64_ID
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#endif // !defined(POC_OS_SET_BY_HAND)



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Determine @c POC_OS_STRING and @c POC_OS_ID
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if defined(POC_OS_UNIX)
#   define POC_OS_STRING POC_OS_UNIX_STRING
#   define POC_OS_ID POC_OS_UNIX_ID
#   error Operating system unknown.
#endif

#if defined(POC_OS_MACOSX)
#   define POC_OS_STRING POS_OS_MACOSX_STRING
#   define POC_OS_ID POC_OS_MACOSX_ID
#   error Operating system unknown.
#endif

#if defined(POC_OS_LINUX)
#   define POC_OS_STRING POC_OS_LINUX_STRING
#   define POC_OS_ID POC_OS_LINUX_ID
#   error Operating system unknown.
#endif

#if defined(POC_OS_WIN)
#   define POC_OS_STRING POC_OS_WIN_STRING
#   define POC_OS_ID POC_OS_WIN_ID
#   error Operating system unknown.
#endif

#if defined(POC_OS_WIN32)
#   define POC_OS_STRING POC_OS_WIN32_STRING
#   define POC_OS_ID POC_OS_WIN32_ID
#   error Operating system unknown.
#endif

#if defined(POC_OS_WIN64)
#   define POC_OS_STRING POC_OS_WIN64_STRING
#   define POC_OS_ID POC_OS_WIN64_ID
#   error Operating system unknown.
#endif

// No known operating system detected
#if !defined(POC_OS_STRING) || !defined(POC_OS_ID)
#   define POC_OS_UNKNOWN POC_OS_UNKNOWN_ID
#   define POC_OS_ID POC_OS_UNKNOWN_ID
#   define POC_OS_STRING POC_OS_UNKNOWN_STRING
#   error Operating system unknown.
#endif

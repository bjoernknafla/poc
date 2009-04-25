/**
 * @file
 *
 * Include @code poc_arch_undef.h  @endcode to undefine all preprocessor symbols potentially set herein.
 */





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Known architecture ids
/// See http://predef.sourceforge.net/index.php for macros defined by language standards, compilers, libraries, etc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///@{
#define POC_ARCH_UNKNOWN_ID 0
#define POC_ARCH_X86_ID 1
#define POC_ARCH_X86_32_ID 2
#define POC_ARCH_x86_64_ID 4
#define POC_ARCH_PPC_ID 8
#define POC_ARCH_PPC64_ID 16
///@}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Known architecture strings
/// See http://predef.sourceforge.net/index.php for macros defined by language standards, compilers, libraries, etc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///@{
#define POC_ARCH_UNKNOWN_STRING "Unknown architecture"
#define POC_ARCH_X86_STRING "x86"
#define POC_ARCH_X86_32_STRING "x86-32"
#define POC_ARCH_x86_64_STRING "x86-64"
#define POC_ARCH_PPC_STRING "PowerPC"
#define POC_ARCH_PPC64_STRING "PowerPC64"
///@}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Detect architecture
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Detect x86_32 (not x86_64)
#if defined(i386) \
|| defined(__i386) \
|| defined(__i386__) \
|| defined(_M_IX86) \
|| defined(_X86_) \
|| defined(__THW_INTEL__) \
|| defined(__I86__) \
|| defined(__INTEL__)
#   define POC_ARCH_X86 1
#   define POC_ARCH_X86_32 1
#   define POC_ARCH_STRING POC_ARCH_X86_32_STRING
#endif


// Detect x86_64 (AMD not (!!) Itanium)
#if defined(__x86_64) || defined(__x86_64__) || defined(__amd64) || defined(__amd64__) || defined(_M_X64)
#   define POC_ARCH_X86 1
#   define POC_ARCH_X86_64 1
#   define POC_ARCH_STRING POC_ARCH_x86_64_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif


// Detect PowerPC and PowerPC64
#if defined(__ppc__) || defined(__ppc64__)
#   define POC_ARCH_PPC 1
#   if defined(__ppc64__)
#       define POC_ARCH_PPC64 1
#       define POC_ARCH_STRING POC_ARCH_PPC64_STRING
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   else
#       define POC_ARCH_STRING POC_ARCH_PPC_STRING
#   endif
#endif


// No known architecture detected
#if !defined(POC_ARCH_STRING)
#   define POC_ARCH_STRING POC_ARCH_UNKNOWN_STRING
#   error Architecture unknown.
#endif


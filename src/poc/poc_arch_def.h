/**
 * @file
 *
 * Include @code poc_arch_undef.h  @endcode to undefine all preprocessor symbols potentially set herein.
 */





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Predefined architecture ids
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
/// @name Predefined architecture strings
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

// If @c POC_OS_SET_BY_HAND is defined no automatic operating system detection should take place.
#if !defined(POC_ARCH_SET_BY_HAND)


// Detect x86_32 (not x86_64)
#if defined(i386) \
|| defined(__i386) \
|| defined(__i386__) \
|| defined(_M_IX86) \
|| defined(_X86_) \
|| defined(__THW_INTEL__) \
|| defined(__I86__) \
|| defined(__INTEL__)
#   define POC_ARCH_X86 POC_ARCH_X86_ID
#   define POC_ARCH_X86_32 POC_ARCH_X86_32_ID
#endif


// Detect x86_64 (AMD not (!!) Itanium)
#if defined(__x86_64) || defined(__x86_64__) || defined(__amd64) || defined(__amd64__) || defined(_M_X64)
#   define POC_ARCH_X86 POC_ARCH_X86_ID
#   define POC_ARCH_X86_64 POC_ARCH_X86_64_ID
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif


// Detect PowerPC and PowerPC64
#if defined(__ppc__) || defined(__ppc64__)
#   define POC_ARCH_PPC POC_ARCH_PPC_ID
#   if defined(__ppc64__)
#       define POC_ARCH_PPC64 POC_ARCH_PPC64_ID
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#endif


#endif // !defined(POC_ARCH_SET_BY_HAND)


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Determine @c POC_ARCH_STRING and @c POC_ARCH_ID
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(POS_ARCH_X86)
#   define POC_ARCH_ID POC_ARCH_X86_ID
#   define POC_ARCH_STRING POC_ARCH_X86_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(POS_ARCH_X86_32)
#   define POC_ARCH_ID POC_ARCH_X86_32_ID
#   define POC_ARCH_STRING POC_ARCH_X86_32_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(POS_ARCH_X86_64)
#   define POC_ARCH_ID POC_ARCH_X86_64_ID
#   define POC_ARCH_STRING POC_ARCH_X86_64_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(POS_ARCH_PPC)
#   define POC_ARCH_ID POC_ARCH_PPC_ID
#   define POC_ARCH_STRING POC_ARCH_PPC_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(POS_ARCH_PPC64)
#   define POC_ARCH_ID POC_ARCH_PPC64_ID
#   define POC_ARCH_STRING  POC_ARCH_PPC64_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif


// No known architecture detected
#if !defined(POC_ARCH_STRING) || !defined(POC_ARCH_ID)
#   define POC_ARCH_UNKNONW POC_ARCH_UNKNOWN_ID
#   define POC_ARCH_ID POC_ARCH_UNKNOWN_ID
#   define POC_ARCH_STRING POC_ARCH_UNKNOWN_STRING
#   error Architecture unknown.
#endif


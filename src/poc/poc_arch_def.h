/**
 * @file
 *
 * Include @code poc_arch_undef.h  @endcode to undefine all preprocessor symbols potentially set herein.
 *
 * @TODO: Detect if running on a CUDA device or on a @c __DEVICE_EMULATION__ and if running on the host or the device.
 * @TODO: Detect if running on a OpenCL host or device and which one the moment this is possible to detect.
 * @TODO: Add support for Cell SPU and PPU.
 * @TODO: Add support for iPhone, iPod Touch, and device emulation.
 */

#if !defined(POC_ARCH_HEADER_DISABLE_DEF_UNDEF)



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Predefined architecture ids
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///@{
#define POC_ARCH_UNKNOWN_ID 0
#define POC_ARCH_X86_32_ID 1
#define POC_ARCH_X86_64_ID 2
#define POC_ARCH_PPC_ID 4
#define POC_ARCH_PPC64_ID 8
#define POC_ARCH_ARM_ID 16
#define POC_ARCH_ARM_THUMB_ID 32
///@}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Predefined architecture strings
/// See http://predef.sourceforge.net/index.php for macros defined by language standards, compilers, libraries, etc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///@{
#define POC_ARCH_UNKNOWN_STRING "Unknown architecture"
#define POC_ARCH_X86_32_STRING "x86-32"
#define POC_ARCH_X86_64_STRING "x86-64"
#define POC_ARCH_PPC_STRING "PowerPC"
#define POC_ARCH_PPC64_STRING "PowerPC64"
#define POC_ARCH_ARM_STRING "ARM"
#define POC_ARCH_ARM_THUMB_STRING "ARM Thumb"
///@}


// If @c POC_ARCH_DISABLE_AUTODETECT or @c POC_DISABLE_AUTODETECT is defined no automatic operating system detection 
// takes place.
#if !defined(POC_ARCH_DISABLE_AUTODETECT) && !defined(POC_DISABLE_AUTODETECT)


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
#   define POC_ARCH_X86 POC_ARCH_X86_32_ID
#   define POC_ARCH_X86_32 POC_ARCH_X86_32_ID
#endif


// Detect x86_64 (AMD not (!!) Itanium)
#if defined(__x86_64) || defined(__x86_64__) || defined(__amd64) || defined(__amd64__) || defined(_M_X64)
#   define POC_ARCH_X86 POC_ARCH_X86_64_ID
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

// Detect ARM and ARM Thumb
#if defined(__arm__) || (__thumb__)
#   if defined(__arm__)
#       define POC_ARCH_ARM POC_ARCH_ARM_ID
#   endif
#   if defined(__thumb__)
#       define POC_ARCH_ARM_THUMB POC_ARCH_ARM_THUMB_ID
#   endif
#endif



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Determine @c POC_ARCH_STRING and @c POC_ARCH_ID
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#if defined(POC_ARCH_X86_32)
#   define POC_ARCH POC_ARCH_X86_32_ID
#   define POC_ARCH_STRING POC_ARCH_X86_32_STRING
#endif

#if defined(POC_ARCH_X86_64)
#   define POC_ARCH POC_ARCH_X86_64_ID
#   define POC_ARCH_STRING POC_ARCH_X86_64_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(POC_ARCH_PPC)
#   define POC_ARCH POC_ARCH_PPC_ID
#   define POC_ARCH_STRING POC_ARCH_PPC_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(POC_ARCH_PPC64)
#   define POC_ARCH POC_ARCH_PPC64_ID
#   define POC_ARCH_STRING  POC_ARCH_PPC64_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(POC_ARCH_ARM)
#   define POC_ARCH POC_ARCH_ARM_ID
#   define POC_ARCH_STRING  POC_ARCH_ARM_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

#if defined(POC_ARCH_ARM_THUMB)
#   define POC_ARCH POC_ARCH_ARM_THUMB_ID
#   define POC_ARCH_STRING  POC_ARCH_ARM_THUMB_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif




#endif // !defined(POC_ARCH_DISABLE_AUTODETECT) && !defined(POC_DISABLE_AUTODETECT)



// No known architecture detected
#if !defined(POC_ARCH)
#   define POC_ARCH_UNKNONW POC_ARCH_UNKNOWN_ID
#   define POC_ARCH POC_ARCH_UNKNOWN_ID
#   error Machine architecture unknown.
#endif 

#if !defined(POC_ARCH_STRING)
#   define POC_ARCH_STRING POC_ARCH_UNKNOWN_STRING
#   error Machine architecture string unknown.
#endif


// Error detection
#if defined(POC_ARCH_X86)
#   if (POC_ARCH_X86 != POC_ARCH_X86_32_ID) && (POC_ARCH_X86 != POC_ARCH_X86_64_ID)
#       error POC_ARCH_X86 set to unknown value.
#   endif
#endif

// Exactly one architecture must have been detected - xor tests to find possible error.
#if defined(POC_ARCH_X86_32) && \
(defined(POC_ARCH_X86_64) || \
 defined(POC_ARCH_PPC) || \
 defined(POC_ARCH_PPC64) || \
 defined(POC_ARCH_ARM) || \
 defined(POC_ARCH_ARM_THUMB) || \
 defined(POC_ARCH_UNKNOWN) )
#   error Exactly one architecture must be selected.
#elif defined(POC_ARCH_X86_64) && \
(defined(POC_ARCH_X86_32) || \
defined(POC_ARCH_PPC) || \
defined(POC_ARCH_PPC64) || \
defined(POC_ARCH_ARM) || \
defined(POC_ARCH_ARM_THUMB) || \
defined(POC_ARCH_UNKNOWN) )
#   error Exactly one architecture must be selected.
#elif defined(POC_ARCH_PPC) && \
(defined(POC_ARCH_X86_64) || \
defined(POC_ARCH_X86_32) || \
defined(POC_ARCH_PPC64) || \
defined(POC_ARCH_ARM) || \
defined(POC_ARCH_ARM_THUMB) || \
defined(POC_ARCH_UNKNOWN) )
#   error Exactly one architecture must be selected.
#elif defined(POC_ARCH_PPC64) && \
(defined(POC_ARCH_X86_64) || \
defined(POC_ARCH_X86_32) || \
defined(POC_ARCH_PPC) || \
defined(POC_ARCH_ARM) || \
defined(POC_ARCH_ARM_THUMB) || \
defined(POC_ARCH_UNKNOWN) )
#   error Exactly one architecture must be selected.
#elif defined(POC_ARCH_ARM) && \
(defined(POC_ARCH_X86_64) || \
defined(POC_ARCH_X86_32) || \
defined(POC_ARCH_PPC64) || \
defined(POC_ARCH_PPC) || \
defined(POC_ARCH_ARM_THUMB) || \
defined(POC_ARCH_UNKNOWN) )
#   error Exactly one architecture must be selected.
#elif defined(POC_ARCH_ARM_THUMB) && \
(defined(POC_ARCH_X86_64) || \
defined(POC_ARCH_X86_32) || \
defined(POC_ARCH_PPC64) || \
defined(POC_ARCH_ARM) || \
defined(POC_ARCH_PPC) || \
defined(POC_ARCH_UNKNOWN) )
#   error Exactly one architecture must be selected.
#elif defined(POC_ARCH_UNKNOWN) && \
(defined(POC_ARCH_X86_64) || \
defined(POC_ARCH_X86_32) || \
defined(POC_ARCH_PPC64) || \
defined(POC_ARCH_ARM) || \
defined(POC_ARCH_ARM_THUMB) || \
defined(POC_ARCH_PPC) )
#   error Exactly one architecture must be selected.
#endif



#endif // !defined(POC_ARCH_HEADER_DISABLE_DEF_UNDEF)


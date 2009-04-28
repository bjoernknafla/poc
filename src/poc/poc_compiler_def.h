

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Predefined compiler ids.
/// @TODO: Move all ids of all POC headers to the value @c 1 to allow binary-logic-or-tests for it.
/// @TODO: Add OpenCL compiler detection.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///@{
#define POC_COMPILER_UNKNOWN_ID 0
#define POC_COMPILER_GCC_ID 1
#define POC_COMPILER_ICC_ID 2
#define POC_COMPILER_MSVC_ID 4
#define POC_COMPILER_OPENCL_GENERIC 8
#define POC_COMPILER_NVCC_ID 16
///@}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Predefined compiler strings.
/// See Intel C++ Compiler Documentation.
/// See http://predef.sourceforge.net/index.php for macros defined by language standards, compilers, libraries, etc. The
/// documents in CVS have significantly less errors than the website.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///@{
#define POC_COMPILER_UNKNOWN_STRING "Unknown compiler"
#define POC_COMPILER_GCC_STRING "GNU GCC"
#define POC_COMPILER_MSVC_STRING "Microsoft Visual Studio C++"
#define POC_COMPILER_ICC_STRING "Intel C/C++"
#define POC_COMPILER_OPENCL_GENERIC_STRING "Generic OpenCL compiler"
#define POC_COMPILER_NVCC_STRING "Nvidia NVCC"
///@}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Compiler version.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///@{
#define POC_COMPILER_VERSION_UNKNOWN -1
#define POC_COMPILER_VERSION_UNKNOWN_STRING "Unkown compiler version"
///@}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Detect compiler.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#if !defined(POC_COMPILER_SET_BY_HAND)


// Detect gcc (and therefor g++).
#if defined(__GNUC__)
#   define POC_COMPILER_GCC POC_COMPILER_GCC_ID
#   if defined(__GNUC_PATCHLEVEL__)
#       define POC_COMPILER_GCC_VERSION (__GNUC__ * 10000 \
+ __GNUC_MINOR__ * 100 \
+ __GNUC_PATCHLEVEL__ )
#   else
#       define POC_COMPILER_GCC_VERSION (__GNUC__ * 10000 \
+ __GNUC_MINOR__ * 100 )
#   endif
#endif

// Detect Microsoft Visual Studio Compiler.
#if defined(_MSC_VER)
#   define POC_COMPILER_MSVC POC_COMPILER_MSVC_ID
#   define POC_COMPILER_MSVC_VERSION _MSC_VER
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

// @TODO: Refactor to extract NVCC compiler version (if possible).
#if defined(__CUDACC__)
#   define POC_COMPILER_NVCC POC_COMPILER_NVCC_ID
#   define POC_COMPILER_NVCC_VERSION POC_COMPILER_UNKNOWN_VERSION
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

// @TODO: Refactor to extract OpenCL compiler version and compiler vendor.
#if defined(__OPENCL_VERSION__)
#   define POC_COMPILER_OPENCL_GENERIC POC_COMPILER_OPENCL_GENERIC_ID
#   define POC_COMPILER_OPENCL_GENERIC_VERSION POC_COMPILER_UNKNOWN_VERSION
#endif


// Detect Intel compiler.
//
// Intel compiler detection must happen after checks for GCC and MSVC because these compiler might be used as hosts
// by ICC and their settings are needed by the following ICC detection preprocessor constructs.
//
// Intel's compiler often uses the systems native compiler infrastructure. If a system has Gnu GCC installed
// POC_COMPILER_GCC is undefined - this is not the compiler used, but as its infrastructure is used
// POC_COMPILER_ICC_GCC is used. POC_COMPILER_ICC_GCC is also used to prefix the detected Gnu GCC 
// version and string describing it.
#if defined(__ICC) || defined(__INTEL_COMPILER)
#   define POC_COMPILER_ICC POC_COMPILER_ICC_ID
#   define POC_COMPILER_ICC_VERSION __INTEL_COMPILER
#   if defined(POC_COMPILER_GCC)
#       define POC_COMPILER_ICC_HOST_GCC POC_COMPILER_GCC_ID
#       define POC_COMPILER_ICC_HOST_GCC_ID POC_COMPILER_GCC_ID
#       define POC_COMPILER_ICC_HOST_GCC_STRING POC_COMPILER_GCC_STRING
#       define POC_COMPILER_ICC_HOST_GCC_VERSION POC_COMPILER_GCC_VERSION
#       define POC_COMPILER_ICC_HOST POC_COMPILER_GCC_ID
#       define POC_COMPILER_ICC_HOST_ID POC_COMPILER_GCC_ID
#       define POC_COMPILER_ICC_HOST_VERSION POC_COMPILER_GCC_VERSION
#       define POC_COMPILER_ICC_HOST_STRING POC_COMPILER_GCC_STRING
#       undef POC_COMPILER_GCC
#       undef POC_COMPILER_GCC_VERSION
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   elif defined(POC_COMPILER_MSVC)
#       define POC_COMPILER_ICC_HOST_MSVC POC_COMPILER_MSVC_ID
#       define POC_COMPILER_ICC_HOST_MSVC_ID POC_COMPILER_MSVC_ID
#       define POC_COMPILER_ICC_HOST_MSVC_VERSION POC_COMPILER_MSVC_VERSION
#       define POC_COMPILER_ICC_HOST_MSVC_STRING POC_COMPILER_MSVC_STRING
#       define POC_COMPILER_ICC_HOST POC_COMPILER_MSVC_ID
#       define POC_COMPILER_ICC_HOST_ID POC_COMPILER_MSVC_ID
#       define POC_COMPILER_ICC_HOST_STRING POC_COMPILER_MSVC_STRING
#       define POC_COMPILER_ICC_HOST_VERSION POC_COMPILER_MSVC_VERSION
#       undef POC_COMPILER_MSVC
#       undef POC_COMPILER_MSVC_VERSION
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   elif
#       define POC_COMPILER_ICC_HOST_UNKNOWN POC_COMPILER_UNKNOWN_ID
#       define POC_COMPILER_ICC_HOST_UNKNOWN_ID POC_COMPILER_UNKNOWN_ID
#       define POC_COMPILER_ICC_HOST_UNKNOWN_VERSION POC_COMPILER_UNKNOWN_VERSION
#       define POC_COMPILER_ICC_HOST_UNKNOWN_STRING POC_COMPILER_UNKNOWN_STRING
#       define POC_COMPILER_ICC_HOST POC_COMPILER_UNKNOWN_ID
#       define POC_COMPILER_ICC_HOST_ID POC_COMPILER_UNKNOWN_ID
#       define POC_COMPILER_ICC_HOST_STRING POC_COMPILER_UNKNOWN_STRING
#       define POC_COMPILER_ICC_HOST_VERSION POC_COMPILER_UNKNOWN_VERSION
#   endif
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif





#endif // !defined(POC_COMPILER_SET_BY_HAND)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Determine @c POC_COMPILER_ID, @c POC_COMPILER_STRING and @c POC_COMPILER_VERSION
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#if defined(POC_COMPILER_GCC)
#   define POC_COMPILER_ID POC_COMPILER_GCC_ID
#   define POC_COMPILER_STRING POC_COMPILER_GCC_STRING
#   define POC_COMPILER_VERSION POC_COMPILER_GCC_VERSION
#endif

#if defined(POC_COMPILER_MSVC)
#   define POC_COMPILER_ID POC_COMPILER_MSVC_ID
#   define POC_COMPILER_STRING POC_COMPILER_MSVC_STRING
#   define POC_COMPILER_VERSION POC_COMPILER_MSVC_VERSION
#endif

#if defined(POC_COMPILER_NVCC)
#   define POC_COMPILER_ID POC_COMPILER_NVCC_ID
#   define POC_COMPILER_STRING POC_COMPILER_NVCC_STRING
#   define POC_COMPILER_VERSION POC_COMPILER_NVCC_VERSION
#endif


#if defined(POC_COMPILER_OPENCL_GENERIC)
#   define POC_COMPILER_ID POC_COMPILER_OPENCL_GENERIC_ID
#   define POC_COMPILER_STRING POC_COMPILER_OPENCL_GENERIC_STRING
#   define POC_COMPILER_VERSION POC_COMPILER_OPENCL_GENERIC_VERSION
#endif


// Icc detection must be last to overwrite values that might have been set by host compilers like GCC or MSVC.
#if defined(POC_COMPILER_ICC)
#   define POC_COMPILER_ID POC_COMPILER_ICC_ID
#   define POC_COMPILER_STRING POC_COMPILER_ICC_STRING
#   define POC_COMPILER_VERSION POC_COMPILER_ICC_VERSION
#endif


// No known compiler detected.
#if !defined(POC_COMPILER_STRING) || !defined(POC_COMPILER_ID)
#   define POC_COMPILER_ID POC_COMPILER_UNKNOWN_ID
#   define POC_COMPILER_STRING POC_COMPILER_UNKNOWN_STRING
#   define POC_COMPILER_VERSION POC_COMPILER_VERSION_UNKNOWN
#   error Compiler unknown.
#endif

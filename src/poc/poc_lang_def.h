
// Include macros prefixed with POC_COMPILER
#include "poc_compiler_def.h"


/// @TODO: Add detection of C++0x the moment they finalize the version number stored in @c __cplusplus .

#define POC_LANG_UNKNOWN_ID 0
#define POC_LANG_C_UNKNOWN_ID 1
#define POC_LANG_C_C89_ID 2
#define POC_LANG_C_C99_ID 4
#define POC_LANG_CPP_UNKNOWN_ID 8
#define POC_LANG_CPP_CPP98_ID 16
#define POC_LANG_OBJC_UNKNOWN_ID 32
#define POC_LANG_OPENCL_UNKNOWN_ID 64



#define POC_LANG_UNKNOWN_STRING "Unknown language"
#define POC_LANG_C_UNKNOWN_STRING "C unknown version"
#define POC_LANG_C_C89_STRING "C C89"
#define POC_LANG_C_C99_STRING "C C99"
#define POC_LANG_CPP_UNKNOWN_STRING "C++ unknown version"
#define POC_LANG_CPP_CPP98_STRING "C++ '98"
#define POC_LANG_OBJC_UNKNOWN_STRING "Objective-C unknown version"
#define POC_LANG_OPENCL_UNKNOWN_STRING "OpenCL unknown version"

#define POC_LANG_C_C89_STANDARDIZED_VERSION 199409L
#define POC_LANG_C_C99_STANDARDIZED_VERSION 199901L
#define POC_LANG_CPP_CPP98_STANDARDIZED_VERSION 199711L


// See http://www.velocityreviews.com/forums/t278643-class-static-variables-amp-stdcversion.html for explanation
// why to add @c 0 to a preprocessor symbol (if a symbol is defined but doesn't represent a number the @code +0 @endcode
// transforms it into a number).
#if defined(__STDC__)
#   if defined(__STDC_VERSION__) && ((__STDC_VERSION__ + 0) == POC_LANG_C_C89_STANDARDIZED_VERSION)
#       define POC_LANG_C POC_LANG_C_C89_ID
#       define POC_LANG_C_C89 POC_LANG_C_C89_ID
#       define POC_LANG_C_STRING POC_LANG_C_C89_STRING
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   elif defined(__STDC_VERSION__) && ((__STDC_VERSION__ + 0) == POC_LANG_C_C99_STANDARDIZED_VERSION)
#       define POC_LANG_C POC_LANG_C_C99_ID
#       define POC_LANG_C_C99 POC_LANG_C_C99_ID
#       define POC_LANG_C_STRING POC_LANG_C_C99_STRING
#   else
#       define POC_LANG_C POC_LANG_C_UNKNOWN_ID
#       define POC_LANG_C_STRING POC_LANG_C_UNKNOWN_STRING
#   endif
#endif


// See http://www.velocityreviews.com/forums/t278643-class-static-variables-amp-stdcversion.html for explanation
// why to add @c 0 to a preprocessor symbol (if a symbol is defined but doesn't represent a number the @code +0 @endcode
// transforms it into a number).
#if defined(__cplusplus)
#   if ((__cplusplus + 0) == POC_LANG_CPP_CPP98_STANDARDIZED_VERSION)
#       define POC_LANG_CPP POC_LANG_CPP_CPP98_ID
#       define POC_LANG_CPP_CPP98 POC_LANG_CPP_CPP98_ID
#       define POC_LANG_CPP_STRING POC_LANG_CPP_CPP98_STRING
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   else
#       define POC_LANG_CPP POC_LANG_CPP_UNKNOWN_ID
#       define POC_LANG_CPP_STRING POC_LANG_CPP_UNKNOWN_STRING
#   endif
#endif


#if defined(__OBJC__)
#   define POC_LANG_OBJC POC_LANG_OBJC_UNKNOWN_ID
#   define POC_LANG_OBJC_STRING POC_LANG_OBJC_UNKNOWN_STRING
// #   if defined(OBJC_NEW_PROPERTIES)
// #    endif
#endif


#if defined(__OPENCL_VERSION__)
#   define POC_LANG_OPENCL POC_LANG_OPENCL_UNKNOWN_ID
#   define POC_LANG_OPENCL_STRING POC_LANG_OPENCL_UNKNOWN_STRING
#   // define POC_LANG_OPENCL_VERSION __OPENCL_VERSION__
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif





#if defined(POC_LANG_C_C99)
#   define POC_LANG_C_TYPE_BOOL_SUPPORT 1
#   define POC_LANG_C_TYPE_LONG_LONG_SUPPORT 1
#   define POC_LANG_C_TYPE_LONG_DOUBLE_SUPPORT 1
#   define POC_LANG_C_HEADER_STDBOOL_SUPPORT 1
#   // Hosted C99 implementation.
#   if defined(__STDC_HOSTED__) && (1 == __STDC_HOSTED__) 
#       define POC_LANG_C_HEADER_STDINT_SUPPORT 1
#       define POC_LANG_C_TYPE_COMPLEX_SUPPORT 1
#       define POC_LANG_C_TYPE_IMAGINARY_SUPPORT 1
#   // Freestanding C99 implementation
#   // It isn't specified if freestanding implementations support complex data types.
#   elif defined(__STDC_HOSTED__) && (0 == __STDC_HOSTED__)  
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.      
#   endif
#   // Compiler performs floating point arithmetic according to the IEC 60559 standard, also known as the 
#   // IEEE 754 standard.
#   if defined(__STDC_IEC_559__) && (1 == __STDC_IEC_559__) 
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   // Compiler performs complex arithmetic according to the IEC 60559 standard.
#   if defined(__STD_IEC_559_COMPLEX__) && (1 == __STD_IEC_559_COMPLEX__) 
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   // Values of the type @c wchar_t are represented by the codes in the ISO/IEC 10646 standard. The macro contains the 
#   // standard revision as an integral value encoded as the year and month if the revision, @c yyyymmL .
#   if defined(__STDC_ISO_10646__) 
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#endif



// Detect if RTTI is for sure enabled for C++. 
// @attention RTTI might even be enabled if the tested macros aren't defined.
#if defined(POC_LANG_CPP)
#   if defined(POC_COMPILER_GCC) && defined(__GXX_RTTI)
#       define POC_LANG_CPP_RTTI_SUPPORT 1
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   if defined(POC_COMPILER_MSVC) && defined(_CPPRTTI)
#       define POC_LANG_CPP_RTTI_SUPPORT 1
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   if defined(POC_COMPILER_ICC) && defined(__INTEL_RTTI__)
#       define POC_LANG_CPP_RTTI_SUPPORT 1
#   endif
#endif

// Detect if exceptions are enabled for C++
#if defined(POC_LANG_CPP)
#   if defined(POC_COMPILER_GCC) && defined(__EXCEPTIONS)
#       define POC_LANG_CPP_EXCEPTIONS_SUPPORT 1
#   endif
#   if defined(POC_COMPILER_MSVC) && defined(_CPPUNWIND)
#       define POC_LANG_CPP_EXCEPTIONS_SUPPORT 1
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   if defined(POC_COMPILER_ICC) && defined(__EXCEPTIONS)
#       define POC_LANG_CPP_EXCEPTIONS_SUPPORT 1
#   endif
#endif


#if defined (POC_LANG_OPENCL)
#   // Detect extensions.
#   if defined(cl_khr_fp64)
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   if defined(cl_khr_select_fprounding_mode)
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   // Possible values for @c __ROUNDING_MODE__ are @code rte, rtz, rtp, rtz @endcode .
#   endif
#   if defined(cl_khr_global_int32_base_atomics)
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   if defined(cl_khr_global_int32_extended_atomics)
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   if defined(cl_khr_local_int32_base_atomics)
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   if defined(cl_khr_local_int32_extended_atomics)
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   if defined(cl_khr_int64_base_atomics)
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   if defined(cl_khr_int64_extended_atomics)
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   if defined(cl_khr_3d_image_writes)
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   if defined(cl_khr_byte_addressable_store)
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   if defined(cl_khr_fp16)
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   endif
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif



#if defined(POC_LANG_C)
#   define POC_LANG POC_LANG_C
#   define POC_LANG_STRING POC_LANG_C_STRING
#endif

#if defined(POC_LANG_CPP)
#   undef POC_LANG
#   undef POC_LANG_STRING
#   define POC_LANG POC_LANG_CPP
#   define POC_LANG_STRING POC_LANG_CPP_STRING
#endif

#if defined(POC_LANG_OBJC)
#   undef POC_LANG
#   undef POC_LANG_STRING
#   define POC_LANG POC_LANG_OBJC
#   define POC_LANG_STRING POC_LANG_OBJC_STRING
#endif

#if defined(POC_LANG_OPENCL)
#   define POC_LANG POC_LANG_OPENCL
#   define POC_LANG_STRING POC_LANG_OBJC_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif

// No known programming language detected.
#if !defined(POC_LANG) || !defined(POC_LANG_STRING)
#   define POC_LANG_UNKNOWN POC_LANG_UNKNOWN_ID
#   define POC_LANG POC_LANG_UNKNOWN_ID
#   define POC_LANG_STRING POC_LANG_UNKNOWN_STRING
#   error Unknown programming language.
#endif

/*
// Exactly one programming language must have been chosen - xor tests to find possible error.
#if defined(POC_LANG_C) && \
(defined(POC_LANG_CPP) || \
defined(POC_LANG_OBJC) || \
defined(POC_LANG_OPENCL) || \
defined(POC_LANG_UNKNOWN))
#   error Exactly one programming language must be selected.
#elif defined(POC_LANG_CPP) && \
(defined(POC_LANG_C) || \
defined(POC_LANG_OBJC) || \
defined(POC_LANG_OPENCL) || \
defined(POC_LANG_UNKNOWN))
#   error Exactly one programming language must be selected.
#elif defined(POC_LANG_OBJC) && \
(defined(POC_LANG_CPP) || \
defined(POC_LANG_C) || \
defined(POC_LANG_OPENCL) || \
defined(POC_LANG_UNKNOWN))
#   error Exactly one programming language must be selected.
#elif defined(POC_LANG_OPENCL) && \
(defined(POC_LANG_CPP) || \
defined(POC_LANG_OBJC) || \
defined(POC_LANG_C) || \
defined(POC_LANG_UNKNOWN))
#   error Exactly one programming language must be selected.
#elif defined(POC_LANG_UNKNOWN) && \
(defined(POC_LANG_CPP) || \
defined(POC_LANG_OBJC) || \
defined(POC_LANG_OPENCL) || \
defined(POC_LANG_C))
#   error Exactly one programming language must be selected.
#endif
*/

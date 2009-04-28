
// Include macros prefixed with POC_COMPILER
// #include "poc_compiler_def.h"


#define POC_LANG_UNKNOWN_ID 0
#define POC_LANG_C_ID 1
#define POC_LANG_C_UNKNOWN_ID 2
#define POC_LANG_C_C89_ID 4
#define POC_LANG_C_C99_ID 8
#define POC_LANG_CPP_ID 16
#define POC_LANG_CPP_UNKNOWN_ID 32
#define POC_LANG_CPP_CPP98_ID 64
#define POC_LANG_CPP_CPP2003_ID 128
#define POC_LANG_OBJC_ID 256
#define POC_LANG_OPENCL_ID 512



#define POC_LANG_UNKNOWN_STRING "Unknown language"
#define POC_LANG_C_STRING "C"
#define POC_LANG_C_UNKNOWN_STRING "Unknown C"
#define POC_LANG_C_C89_STRING "C C89"
#define POC_LANG_C_C99_STRING "C C99"
#define POC_LANG_CPP_STRING "C++"
#define POC_LANG_CPP_UNKNOWN_STRING "Unknown C++"
#define POC_LANG_CPP_CPP98_STRING "C++ '98"
#define POC_LANG_OBJC_STRING "Objective-C"
#define POC_LANG_OPENCL_STRING "OpenCL"

#define POC_LANG_C_C89_VERSION 199409L
#define POC_LANG_C_C99_VERSION 199901L
#define POC_LANG_CPP_CPP98_VERSION 199711L


// See http://www.velocityreviews.com/forums/t278643-class-static-variables-amp-stdcversion.html for explanation
// why to add @c 0 to a preprocessor symbol (if a symbol is defined but doesn't represent a number the @code +0 @endcode
// transforms it into a number).
#if defined(__STDC__)
#   if defined(__STDC_VERSION__) && ((__STDC_VERSION__ + 0) == POC_LANG_C_C89_VERSION)
#       define POC_LANG_C (POC_LANG_C_ID | POC_LANG_C_C89_ID)
#       define POC_LANG_C_C89 POC_LANG_C_C89_ID
#   elif defined(__STDC_VERSION__) && ((__STDC_VERSION__ + 0) == POC_LANG_C_C99_VERSION)
#       define POC_LANG_C (POC_LANG_C_ID | POC_LANG_C_C99_ID)
#       define POC_LANG_C_C99 POC_LANG_C_C99_ID
#   else
#       define POC_LANG_C POC_LANG_C_ID
#   endif


// See http://www.velocityreviews.com/forums/t278643-class-static-variables-amp-stdcversion.html for explanation
// why to add @c 0 to a preprocessor symbol (if a symbol is defined but doesn't represent a number the @code +0 @endcode
// transforms it into a number).
#if defined(__cplusplus)
#   if ((__cplusplus + 0) == POC_LANG_CPP_CPP98_VERSION)
#       define POC_LANG_CPP (POC_LANG_CPP_ID | POC_LANG_CPP_CPP98_ID)
#       define POC_LANG_CPP_CPP98 POC_LANG_CPP_CPP98_ID
#   else
#       define POC_LANG_CPP POC_LANG_CPP_ID      
#   endif


#if defined(__OBJC__)
#   define POC_LANG_OBJC POC_LANG_OBJC_ID
#endif


#if defined(__OPENCL_VERSION__)
#   define POC_LANG_OPENCL POC_LANG_OPENCL_ID
#endif





#if defined(POC_LANG_C_C99)
#   define POC_LANG_C_TYPE_BOOL_SUPPORT
#   define POC_LANG_C_TYPE_LONG_LONG_SUPPORT
#   define POC_LANG_C_TYPE_LONG_DOUBLE_SUPPORT
#   define POC_LANG_C_TYPE_COMPLEX_SUPPORT
#   define POC_LANG_C_TYPE_IMAGINARY_SUPPORT
#   define POC_LANG_C_HEADER_STDBOOL_SUPPORT
#   if defined(__STDC_HOSTED__) && (1 == __STD_HOSTED__)
#       define POC_LANG_C_HEADER_STDINT_SUPPORT
#   endif
#endif




#error Implement.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Predefined language features
///
/// Beware: http://predef.sourceforge.net/prestd.html defines a wrong version number for @c __cplusplus.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///@{
#define POC_LANG_C_VERSION_C99 199901L
#define POC_LANG_C_VERSION_C99_STRING "199901L"

#define POC_LANG_CPP_VERSION_CPP98 199711L
#define POC_LANG_CPP_VERSION_CPP98_STRING "199711L"

#define POC_LANG_C_VERSION_UNKNOWN_STRING "Unknown C version"
#define POC_LANG_CPP_VERSION_UNKNOWN_STRING "Unknown C++ version"
///@}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Detect language features
// See http://www.velocityreviews.com/forums/t278643-class-static-variables-amp-stdcversion.html for explanation
// why to add @c 0 to a preprocessor symbol (if a symbol is defined but doesn't represent a number the @code +0 @endcode
// transforms it into a number).
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Detect C
//
// @todo Complete with C89 and the other C standards.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if defined(__STDC__)
#   if defined(__STD_VERSION__) && (__STD_VERSION__ + 0 == POC_LANG_C_VERSION_C99)
#       define POC_LANG_C_VERSION POC_LANG_C_VERSION_C99
#       define POC_LANG_C_VERSION_STRING POC_LANG_C_VERSION_C99_STRING
#       define POC_LANC_C POC_LANG_C_VERSION_C99
#       define POC_LANG_C_STDC99 POC_LANG_C_VERSION_C99
#       define POC_LANG_C_TYPE_LONGLONG long long
#       if defined(__STD_HOSTED__)
#           define POC_LANG_C_STD_HOSTED __STD_HOSTED__
#           error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#       else
#           error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#       endif
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   else
#       define POC_LANG_C_VERSION __STDC__
#       define POC_LANG_C_VERSION_STRING POC_LANG_C_VERSION_UNKNOWN_STRING
#       define POC_LANG_C __STDC__
#   endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Detect C++
//
// @todo Complete with C++0x standard.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if defined(__cplusplus)
#   if (__cplusplus + 0 == POC_LANG_CPP_VERSION_CPP98)
#       define POC_LANG_CPP_VERSION POC_LANG_CPP_VERSION_CPP98
#       define POC_LANG_CPP_VERSION_STRING POC_LANG_CPP_VERSION_CPP98_STRING
#       define POC_LANG_CPP POC_LANG_CPP_VERSION
#       define POC_LANG_CPP_STDCPP98 POC_LANG_CPP_VERSION
#       error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#   else
#       define POC_LANG_CPP_VERSION __cplusplus
#       define POC_LANG_CPP_VERSION_STRING POC_LANG_CPP_VERSION_UNKNOWN_STRING
#       define POC_LANG_CPP __cplusplus
#   endif
#endif

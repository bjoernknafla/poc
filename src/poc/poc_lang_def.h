
// Include macros prefixed with POC_COMPILER
#include "poc_compiler_def.h"



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


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Detect if the language knows the restrict keyword.
//
// @todo Complete
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if defined(POC_LANG_C_STDC99)
#   define POC_RESTRICT restrict
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#else
#   define POC_RESTRICT
#endif


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Detect and set inline directives.
//
// @todo Complete.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if defined(POC_LANG_C_STDC99) || defined(POC_LANG_CPP)
#   define POC_INLINE inline
#else
#   define POC_INLINE
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Detect and set memory alignment directives.
// 
// Be carefull when using the alignment values that the value of @c POC_ALIGN_BEGIN( val ) and the value of the
// corresponding @c POC_ALIGN_END( val ) are equal.
//
// See @example platform_config_lang_test.cpp for an example how to use the alignment macros.
// 
// @todo Check if ALIGN is correctly used (do the directives assume bit-sized or byte-sized values?).
// @todo Implement.
// @todo Move alignment into its own header and possibly put it into the memory sub-project.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if defined(POC_COMPILER_GCC) // Uses byte-alignment-values
#   define POC_ALIGN_BEGIN( ALIGN )
#   define POC_ALIGN_END( ALIGN ) __attribute__((__aligned__( ALIGN )))
// #   define POC_ALIGN_MAX_BEGIN
// #   define POC_ALIGN_MAX_END __attribute__((__aligned__))
#elif defined(POC_COMPILER_ICC) // Uses byte-alignment-values, for Intel C++ 10.1 alignment values of 8 don't work.
#   define POC_ALIGN_BEGIN( ALIGN ) __declspec(align( ALIGN ))
#   define POC_ALIGN_END( ALIGN )
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#elif defined(POC_COMPILER_MSVC)
#   define POC_ALIGN_BEGIN( ALIGN ) __declspec(align( ALIGN ))
#   define POC_ALIGN_END( ALIGN )
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#else
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif


#define IDM_RESTRICT POC_RESTRICT
#define IDM_INLINE POC_INLINE
#define IDM_ALIGN_BEGIN( ALIGN ) POC_ALIGN_BEGIN( ALIGN )
#define IDM_ALIGN_END( ALIGN ) POC_ALIGN_END( ALIGN )
// #   define IDM_ALIGN_MAX_BEGIN POC_ALIGN_MAX_BEGIN
// #   define IDM_ALIGN_MAX_END POC_ALIGN_MAX_END


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Detect and set visibility when importing or exporting symbols from libraries or DLLs.
//
// @todo Implement.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


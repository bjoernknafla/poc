#ifndef POC_poc_platform_H
#define POC_poc_platform_H

#include <stddef.h>


#include "poc.h"
#include "poc_portability_macros.h"
// #include "poc_platform_stddef.h"
#include "poc_platform_stdbool.h"
#include "poc_platform_inttypes.h"

/* Define @c POC_BOOL, @c POC_TRUE, and @c POC_FALSE */
#if defined(POC_LANG_CPP)
#   define POC_BOOL bool
#   define POC_TRUE true
#   define POC_FALSE false
#elif defined(POC_LANG_OBJC)
#   define POC_BOOL BOOL
#   define POC_TRUE YES
#   define POC_FALSE NO 
#elif defined(POC_LANG_OPENCL)
#   define POC_BOOL bool
#   define POC_TRUE true
#   define POC_FALSE false
#elif (POC_LANG_C < POC_LANG_C_C99_ID)
#   define POC_BOOL int
#   define POC_TRUE 1
#   define POC_FALSE 0
#elif(POC_LANG_C_C99_ID)
#   define POC_BOOL _Bool
#   define POC_TRUE 1
#   define POC_FALSE 0
#else
#   error Unknown boolean type of language.
#endif




/* Define platform independent sized integral types */
#if defined(POC_LANG_C_C99)
#   include <stdint.h>
#   include <stddef.h>
#   define POC_BYTE uint8_t
#   define POC_CHAR char
#   define POC_SIGNED_CHAR signed char
#   define POC_UNSIGNED_CHAR unsigned char
#   define POC_INT8 int8_t
#   define POC_UINT8 uint8_t
#   define POC_INT16 int16_t
#   define POC_UINT16 uint16_t
#   define POC_INT32 int32_t
#   define POC_UINT32 uint32_t
#   if defined(INT64_MIN) /* Do 64bit integral types exist? */
#       define POC_INT64 int64_t
#       define POC_UINT64 uint64_t
#   endif
#   define POC_INTPTR_T intptr_t
#   define POC_UINTPTR_T uintptr_t
#   define POC_PTRDIFF_T ptrdiff_t
#   define POC_SIZE_T size_t
#   /* define POC_IEEE_754 1 */
#   define POC_FLOAT32 float
#   define POC_FLOAT64 double
#elif defined(POC_LANG_CPP_CPP2010)
#   include <cstdint>
#   include <cstddef>
#   define POC_BYTE std::uint8_t
#   define POC_CHAR char
#   define POC_SIGNED_CHAR signed char
#   define POC_UNSIGNED_CHAR unsigned char
#   define POC_INT8 std::int8_t
#   define POC_UINT8 std::uint8_t
#   define POC_INT16 std::int16_t
#   define POC_UINT16 std::uint16_t
#   define POC_INT32 std::int32_t
#   define POC_UINT32 std::uint32_t
#   if defined(INT64_MIN) /* Do 64bit integral types exist? */
#       define POC_INT64 std::int64_t
#       define POC_UINT64 std::uint64_t
#   endif
#   define POC_INTPTR_T std::intptr_t
#   define POC_UINTPTR_T std::uintptr_t
#   define POC_PTRDIFF_T std::ptrdiff_t
#   define POC_SIZE_T std::size_t
#   /* define POC_IEEE_754 1 */
#   define POC_FLOAT32 float
#   define POC_FLOAT64 double
#elif defined(POC_COMPILER_GCC) && (POC_COMPILER_GCC_VERSION >= )

#elif defined(POC_COMPILER_MSVC) && (POC_COMPILER_MSVC_VERSION >= )

#elif defined(POC_COMPILER_ICC) && (POC_COMPILER_ICC_VERSION >= )


#elif defined(POC_LANG_OPENCL)
#   /* Based on OpenCL Specification 1.0.33 */
#   define POC_BYTE unsigned char
#   define POC_CHAR char
#   define POC_SIGNED_CHAR signed char
#   define POC_UNSIGNED_CHAR unsigned char
#   define POC_INT8 signed char
#   define POC_UINT8 unsigned char
#   define POC_INT16 short
#   define POC_UINT16 unsigned short
#   define POC_INT32 int
#   define POC_UINT32 unsigned int
#   define POC_INT64 long
#   define POC_UINT64 unsigned long
#   define POC_INTPTR_T intptr_t
#   define POC_UINTPTR_T uintptr_t
#   define POC_PTRDIFF_T ptrdiff_t
#   define POC_SIZE_T size_t
#   /* define POC_IEEE_754 1 */
#   define POC_FLOAT32 float
#   define POC_FLOAT64 double
#else
#   error Unknown integral, floating point, and pointer bit-sizes.
#endif


#endif /* POC_poc_platform_H */

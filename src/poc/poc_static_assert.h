/**
 * @file
 *
 * Pure C++ helper header defining a compile time (static) assert macro.
 */

#ifndef POC_poc_poc_static_assert_H
#define POC_poc_poc_static_assert_H



// @TODO: Decide if undef @c POC_STATIC_ASSERT instead of generating a compile time error.
#if defined(POC_STATIC_ASSERT)
#   error POC_STATIC_ASSERT macro shouldn't be defined at this point.
#endif


#include "poc_preprocessor_utilities.h"

#include "poc_static_assert_def.h"

// If user includes this header certain undefines aren't allowed in this compilation unit anymore.
#define POC_STATIC_ASSERT_HEADER_DISABLE_DEF_UNDEF


#endif // POC_poc_poc_static_assert_H

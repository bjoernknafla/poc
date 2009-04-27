
// Only allow undef of static assertion macros if @c poc_static_assert.h hasn't been included in this compilation unit.
#if !defined(POC_STATIC_ASSERT_UNDEF_NOT_ALLOWED)
#   undef POC_STATIC_ASSERT
#   include "poc_utility_macros_undef.h"
#endif



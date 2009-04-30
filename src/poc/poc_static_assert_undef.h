
// Only allow undef of static assertion macros if @c poc_static_assert.h hasn't been included in this compilation unit.
#if !defined(POC_STATIC_ASSERT_HEADER_DISABLE_DEF_UNDEF)

#   undef POC_STATIC_ASSERT

#   include "poc_preprocessor_utilities_undef.h"

#endif // !defined(POC_STATIC_ASSERT_HEADER_DISABLE_DEF_UNDEF)



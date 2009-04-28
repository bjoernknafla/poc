
// Only allow undef of utility macros if @c poc_static_assert.h hasn't been included in this compilation unit.
#if !defined(POC_UTILITY_MACROS_UNDEF_NOT_ALLOWED)
#   undef POC_STRINGS_MAX_LENGTH
#   undef POC_CONCAT
#   undef POC_DO_CONCAT
#   undef POC_DO_CONCAT_2
#   undef POC_STRINGIZE
#   undef POC_DO_STRINGIZE
#endif

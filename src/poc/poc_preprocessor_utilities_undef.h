
// Only allow undef of utility macros if @c poc_static_assert.h hasn't been included in this compilation unit.
#if !defined(POC_PREPROCESSOR_UTILITIES_HEADER_DISABLE_DEF_UNDEF)

#   undef POC_STRINGS_MAX_LENGTH
#   undef POC_CONCAT
#   undef POC_DO_CONCAT
#   undef POC_DO_CONCAT_2
#   undef POC_STRINGIZE
#   undef POC_DO_STRINGIZE


#endif // !defined(POC_PREPROCESSOR_UTILITIES_HEADER_DISABLE_DEF_UNDEF)

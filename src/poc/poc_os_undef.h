/**
 * @file
 *
 * Undefines all preprocessor symbols potentially set by @c poc_os_def.h.
 *
 * @attention This header doesn't have header guards to allow successive inclusion.
 */


#if !defined(POC_OS_HEADER_DISABLE_DEF_UNDEF)

#undef POC_OS
#undef POC_OS_STRING

#undef POC_OS_UNKNOWN
#undef POC_OS_UNKNOWN_ID
#undef POC_OS_UNKNOWN_STRING

#undef POC_OS_UNIX
#undef POC_OS_UNIX_ID
#undef POC_OS_UNIX_STRING

#undef POC_OS_MACOSX
#undef POC_OS_MACOSX_ID
#undef POC_OS_MACOSX_STRING

#undef POC_OS_LINUX
#undef POC_OS_LINUX_ID
#undef POC_OS_LINUX_STRING

#undef POC_OS_WIN
#undef POC_OS_WIN_ID
#undef POC_OS_WIN_STRING

#undef POC_OS_WIN32
#undef POC_OS_WIN32_ID
#undef POC_OS_WIN32_STRING

#undef POC_OS_WIN64
#undef POC_OS_WIN64_ID
#undef POC_OS_WIN64_STRING



#endif // !defined(POC_OS_HEADER_DISABLE_DEF_UNDEF)

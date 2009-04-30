
#ifndef POC_poc_preprocessor_utilities_H
#define POC_poc_preprocessor_utilities_H


#if defined( POC_CONCAT )
#   error POC_CONCAT macro shouldn't be defined at this point.
#endif

#if defined( POC_DO_CONCAT )
#   error POC_DO_CONCAT macro shouldn't be defined at this point.
#endif


#if defined( POC_DO_CONCAT_2 )
#   error POC_DO_CONCAT_2 macro shouldn't be defined at this point.
#endif

#if defined(POC_STRINGIZE)
#   error POC_STRINGIZE macro shouldn't be defined at this point.
#endif

#if defined(POC_DO_STRINGIZE)
#   error POC_DO_STRINGIZE macro shouldn't be defined at this point.
#endif



#include "poc_preprocessor_utilities_def.h"

#define POC_PREPROCESSOR_UTILITIES_HEADER_DISABLE_DEF_UNDEF


#endif // POC_poc_preprocessor_utilities_H

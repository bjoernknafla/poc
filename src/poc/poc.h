

/**
 * @file
 *
 * Preprocessor symbols to detect the target platform the code is compiled for.
 *
 * When adding new platforms (operating system, compiler, architecture, C/C++ standards, etc.) then 
 * first add the following code into every detection branch 
 * @code 
 * #error Untested. Remove error preprocessor directive after having ported and tested the code to the platform. 
 * @endcode .
 * 
 * Only remove the preprocessor error directive after having ported and tested the code on the platform!
 *
 * See http://predef.sourceforge.net/index.php for macros defined by language standards, compilers, libraries, etc.
 */

#ifndef POC_poc_H
#define POC_poc_H


/// @TODO: Add undef not allowed preprocessor macros to all include guard secured headers and only allow undefs in the
///        undef headers if these preprocessor symbols aren't defined.

#include "poc_os.h"
#include "poc_compiler.h"
#include "poc_arch.h"
#include "poc_data_model.h"
#include "poc_endian.h"
#include "poc_lang.h"
#include "poc_posix.h"

#endif // POC_poc_H

README.txt

POC is free software. You may copy, distribute, and modify it under the terms of the License contained in the file 
LICENSE.txt distributed with this package. This license is the same as the BSD License.

POC (Portable Preprocessor Compile-time Target Platform Configurator) is a collection of C preprocessor symbols to
manually select or automatically detect certain properties of the target platform compiling for, e.g. the compiler used,
the target operating system, or target data model, etc. 


Use the preprocessor symbols prefixed with POC_ to detect the target platform the code is compiled for and to allow
cross platform compatible keywords, for example to align data types on the stack.

Use POC to detect the target platform the code unit is compiled for, for example:
- POC_ARCH stores an id identifying the machine architecture
- POC_COMPILER stores an id identifying the used compiler, POC_COMPILER_VERSION stores a number representing
  the compiler version
- POC_DATA_MODEL stores an id identifying the platforms data model alas the bit-count of integral, floating point,
  and pointer types.
- POC_ENDIAN stores an id identifying the endianess of the platform.
- POC_LANG stores an id identifying the language (C, C++, Objective-C, OpenCL, CUDA, etc.) compiling for.
- POC_OS stores an id identifying the target operating system.

Each of these preprocessor symbols (other than the ones ending with _VERSION) is accompanied by a macro 
with a _STRING postfix that stores a character string describing the macro's value.

In addition, each compiler, architecture, language, etc. also defines a specific macro when detected, e.g.
POC_ARCH_X86_32 is defined if compiling for a 32bit x86 machine architecture. POC_ARCH and POC_ARCH_X86_32
are both set to an (always) predefined POC_ARCH_X86_32_ID macro.

If no known language, compiler, or endianess could be determined special UNKNOWN ids and strings are used as
values, e.g. POC_OS might be set to POC_OS_UNKNOWN_ID and POC_OS_STRING is set to POC_OS_UNKNOWN_STRING .

See poc_diagnose_main.c for an example how to use POC's platform detection macros.


It is possible to suppress automatic platform detection for everything POC detects by defining
POC_DISABLE_AUTODETECT , or to disable the auto-detection for a specific platform attribue, e.g. to suppress
compiler detection define POC_COMPILER_DISABLE_AUTODETECT .
By disabling the platform auto-detection it is possible to provide self-defined macros, e.g. to set the compiler
yourself define POC_COMPILER_DISABLE_AUTODETECT, and then POC_COMPILER, POC_COMPILER_STRING, 
POC_COMPILER_VERSION, and possible also define a preprocessor macro for the compiler you are
setting, e.g. POC_COMPILER_IBM_XLC for IBM's XL C/C++ compiler.
 

Aside the platform detection macros POC also defines preprocessor symbols to allow portable usage of keywords to:
- Align data types automatically on the stack by wrapping the type in POC_ALIGN_BEING(<byte-alignment>) and
  POC_ALIGN_END(<byte-alignment>) macros.
- Using POC_RESTRICT to enable C99's restrict keyword or disable it when compiling for other languages that
  don't support it.


When adding new platforms (operating system, compiler, architecture, C/C++ standards, etc.) then 
first add the following code into every detection branch 

#error Untested. Remove error preprocessor directive after having ported and tested the code to the platform. 

 
Only remove the preprocessor error directive after having ported and tested the code on the platform!
Don't forget to check that your POC STRING macros are at most POC_STRINGS_MAX_LENGTH characters long
(see poc_preprocessor_utilities_def.h). 

See doc/notes/how_to_extend_poc.txt for more detailed informations how to extend POC.

The error-directive is also present if a platform couldn't be tested yet - remove it but be warned that the code isn't 
tested and might possibly be erroreneous.



The code can be found and downloaded at: http://github.com/bknafla/poc
Please file issues with the code at: http://github.com/bknafla/poc/issues
Follow updates on Twitter at: http://twitter.com/bknafla


All trademarks belong to their trademark holders.



Author:
Bjoern Knafla (poc@bjoernknafla.com)

References:

GCC infos
- Find out which preprocessor symbols are defined by GCC by executing: touch file.cpp && cpp -dM file.cpp
  http://gcc.gnu.org/onlinedocs/cpp/Common-Predefined-Macros.html

GCC with Apple extensions infos
- http://developer.apple.com/documentation/DeveloperTools/gcc-4.2.1/cpp/Standard-Predefined-Macros.html#Standard-Predefined-Macros
- http://developer.apple.com/technotes/tn2002/tn2071.html#Section10
- http://discussions.apple.com/thread.jspa?threadID=1937142&tstart=0

Microsoft Visual Studio C++ infos
- http://msdn.microsoft.com/en-us/library/b0084kay.aspx
- http://msdn.microsoft.com/en-us/library/b0084kay(VS.71).aspx
- http://msdn.microsoft.com/en-us/library/b0084kay(VS.80).aspx

Cell PPU and SPU infos
- http://www-01.ibm.com/chips/techlib/techlib.nsf/techdocs/30B3520C93F437AB87257060006FFE5E/$file/Language_Extensions_for_CBEA_2.5.pdf
- http://www-01.ibm.com/chips/techlib/techlib.nsf/techdocs/1AEEE1270EA2776387257060006E61BA/$file/CBEA_v1.02_11Oct2007_pub.pdf

Other resources
- Apache C++ Standard Library Wiki with lots of cross-platform infos
  http://wiki.apache.org/stdcxx/Compilers
- Collection of macros defined by language standards, compilers, libraries, etc.:
  http://predef.sourceforge.net/index.php 



Release Notes:
Version 0.2.0 (May 5, 2009)
- Code is ANSI C compatible
- Extended documentation
- poc_diagnose_main.c compiles and runs on Windows XP using MS Visual Studio 2008

Version 0.1.0 (May 1, 2009)
- Initial release

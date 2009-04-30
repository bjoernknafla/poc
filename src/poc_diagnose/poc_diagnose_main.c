/**
 * @file
 *
 * App that outputs POC's compile time target configuration to stdout.
 */

// Include EXIT_SUCCESS
#include <stdlib.h>

// Include stdout, fprintf, FILE
#include <stdio.h>





char const* c_cpp_std_macro_date_string = "__DATE__";
char const* c_cpp_std_macro_time_string = "__TIME__";
char const* c_cpp_std_macro_file_string = "__FILE__";
char const* c_cpp_std_macro_line_string = "__LINE__";
char const* c_cpp_std_macro_cplusplus_string = "__cplusplus";
char const* c_cpp_std_macro_stdc_string = "__STDC__";
char const* c_cpp_std_macro_stdc_hosted_string = "__STDC_HOSTED__";
char const* c_cpp_std_macro_stdc_version_string = "__STDC_VERSION__";
char const* c_cpp_std_macro_stdc_iec_559_string = "__STDC_IEC_559__";
char const* c_cpp_std_macro_stdc_iec_559_complex_string = "__STDC_IEC_559_COMPLEX__";
char const* c_cpp_std_macro_stdc_iso_10646_string = "__STDC_ISO_10646__";
char const* c_cpp_std_macro_ndebug_string = "NDEBUG";


typedef struct std_c_cpp_predefined_macros_t
    {
        int is_date_defined;
        char const* date_string;
        
        int is_time_defined;
        char const* time_string;
        
        int is_file_defined;
        char const* file_string;
        
        int is_line_defined;
        long line_integral;
        
        int is_cplusplus_defined;
        long cplusplus_integral;
        
        int is_stdc_defined;
        long stdc_integral;
        
        int is_stdc_hosted_defined;
        long stdc_hosted_integral;
        
        int is_stdc_version_defined;
        long stdc_version_integral;
        
        int is_stdc_iec_559_defined;
        long stdc_iec_559_integral;
        
        int is_stdc_iec_559_complex_defined;
        long stdc_iec_559_complex_integral;
        
        int is_stdc_iso_10646_defined;
        long stdc_iso_10646_integral;
        
        int is_ndebug_defined;
        long ndebug_integral;
        
    } std_c_cpp_predefined_macros;



std_c_cpp_predefined_macros make_std_c_cpp_predefined_macros(void);

int print_macro_definition_string(FILE* outstream, 
                                  char const* macro_description_string, 
                                  int is_macro_defined, 
                                  char const* value_string);

int print_macro_definition_integral(FILE* outstream, 
                                    char const* macro_description_string, 
                                    int is_macro_defined, 
                                    long value_integral);

void print_std_predefined_macros(FILE* outstream);
void print_lang(FILE* outstream);
void print_data_model(FILE* outstream);
void print_compiler(FILE* outstream);
void print_arch(FILE* outstream);
void print_endian(FILE* outstream);
void print_os(FILE* outstream);


std_c_cpp_predefined_macros make_std_c_cpp_predefined_macros(void)
{
    std_c_cpp_predefined_macros std_macros = {
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0
    };
    
#if defined(__DATE__)
    std_macros.is_date_defined = 1;
    std_macros.date_string = __DATE__;
#endif
    
#if defined(__TIME__)
    std_macros.is_time_defined = 1;
    std_macros.time_string = __TIME__;
#endif
    
#if defined(__FILE__)
    std_macros.is_file_defined = 1;
    std_macros.file_string = __FILE__;
#endif
    
#if defined(__LINE__)
    std_macros.is_line_defined = 1;
    std_macros.line_integral = __LINE__;
#endif
    
#if defined(__cplusplus)
    std_macros.is_cplusplus_defined = 1;
    std_macros.cplusplus_integral = __cplusplus;
#endif
    
#if defined(__STDC__)
    std_macros.is_stdc_defined = 1;
    std_macros.stdc_integral = __STDC__;
#endif
    
#if defined(__STDC__HOSTED__)
    std_macros.is_stdc_hosted_defined = 1;
    std_macros.stdc_hosted_integral = __STDC_HOSTED__;
#endif
    
#if defined(__STDC_VERSION__)
    std_macros.is_stdc_version_defined = 1;
    std_macros.stdc_version_integral = __STDC_VERSION__;
#endif
    
#if defined(__STDC_IEC_559__)
    std_macros.is_stdc_iec_559_defined = 1;
    std_macros.stdc_iec_559_integral = __STDC_IEC_559__;
#endif
    
#if defined(__STDC_IEC_559_COMPLEX__)
    std_macros.is_stdc_iec_559_complex_defined = 1;
    std_macros.stdc_iec_559_complex_integral = __STDC_IEC_559_COMPLEX__;
#endif
    
#if defined(__STDC_ISO_10646__)
    std_macros.is_stdc_iso_10646_defined = 1;
    std_macros.stdc_iso_10646_integral = __STDC_ISO_10646__;
#endif
    
#if defined(NDEBUG)
    std_macros.is_ndebug_defined = 1;
    std_macros.ndebug_integral = NDEBUG;
#endif
    
    return std_macros;
}


int print_macro_definition_string(FILE* outstream, 
                                  char const* macro_description_string, 
                                  int is_macro_defined, 
                                  char const* value_string)
{
    int chars_written = 0;
    int const chars_written_description = fprintf(outstream, "  %s ", macro_description_string);
    
    if (0 > chars_written_description)
    {
        return chars_written_description;
    }
    
    chars_written += chars_written_description;
    
    if (is_macro_defined)
    {
        int const chars_written_value = fprintf(outstream, "%s", value_string);
        
        if (0 > chars_written_value)
        {
            return chars_written_value;
        }
        
        chars_written += chars_written_value;
    }
    else
    {
        int const chars_written_undefined = fprintf(outstream, "undefined");
        
        if (0 > chars_written_undefined)
        {
            return chars_written_undefined;
        }
        
        chars_written += chars_written_undefined;
    }
    
    int const chars_written_newline = fprintf(outstream, "\n");
    
    if (0 > chars_written_newline)
    {
        return chars_written_newline;
    }
    
    chars_written += chars_written_newline;
    
    
    return chars_written;
}



int print_macro_definition_integral(FILE* outstream, 
                                    char const* macro_description_string, 
                                    int is_macro_defined, 
                                    long value_integral)
{
    int chars_written = 0;
    int const chars_written_description = fprintf(outstream, "  %s ", macro_description_string);
    
    if (0 > chars_written_description)
    {
        return chars_written_description;
    }
    
    chars_written += chars_written_description;
    
    if (is_macro_defined)
    {
        int const chars_written_value = fprintf(outstream, "%ld", value_integral);
        
        if (0 > chars_written_value)
        {
            return chars_written_value;
        }
        
        chars_written += chars_written_value;
    }
    else
    {
        int const chars_written_undefined = fprintf(outstream, "undefined");
        
        if (0 > chars_written_undefined)
        {
            return chars_written_undefined;
        }
        
        chars_written += chars_written_undefined;
    }
    
    int const chars_written_newline = fprintf(outstream, "\n");
    
    if (0 > chars_written_newline)
    {
        return chars_written_newline;
    }
    
    chars_written += chars_written_newline;
    
    
    return chars_written;
}


void print_std_predefined_macros(FILE* outstream)
{
    
    std_c_cpp_predefined_macros std_macros = make_std_c_cpp_predefined_macros();
    
    fprintf(outstream, "Predefined standard preprocessor macros detection");
    fprintf(outstream, "\n");
    
    
    print_macro_definition_string(outstream, 
                                  c_cpp_std_macro_date_string, 
                                  std_macros.is_date_defined, 
                                  std_macros.date_string);
    
    print_macro_definition_string(outstream, 
                                  c_cpp_std_macro_time_string, 
                                  std_macros.is_time_defined, 
                                  std_macros.time_string);
    
    print_macro_definition_string(outstream, 
                                  c_cpp_std_macro_file_string, 
                                  std_macros.is_file_defined, 
                                  std_macros.file_string);
    
    print_macro_definition_integral(outstream, 
                                    c_cpp_std_macro_line_string, 
                                    std_macros.is_line_defined, 
                                    std_macros.line_integral);
    
    print_macro_definition_integral(outstream, 
                                    c_cpp_std_macro_cplusplus_string, 
                                    std_macros.is_cplusplus_defined, 
                                    std_macros.cplusplus_integral);
    
    print_macro_definition_integral(outstream, 
                                    c_cpp_std_macro_stdc_string, 
                                    std_macros.is_stdc_defined, 
                                    std_macros.stdc_integral);
    
    print_macro_definition_integral(outstream, 
                                    c_cpp_std_macro_stdc_hosted_string, 
                                    std_macros.is_stdc_hosted_defined, 
                                    std_macros.stdc_hosted_integral);
    
    print_macro_definition_integral(outstream, 
                                    c_cpp_std_macro_stdc_version_string, 
                                    std_macros.is_stdc_version_defined, 
                                    std_macros.stdc_version_integral);
    
    print_macro_definition_integral(outstream, 
                                    c_cpp_std_macro_stdc_iec_559_string, 
                                    std_macros.is_stdc_iec_559_defined, 
                                    std_macros.stdc_iec_559_integral);
    
    print_macro_definition_integral(outstream, 
                                    c_cpp_std_macro_stdc_iec_559_complex_string, 
                                    std_macros.is_stdc_iec_559_complex_defined, 
                                    std_macros.stdc_iec_559_complex_integral);
    
    print_macro_definition_integral(outstream, 
                                    c_cpp_std_macro_stdc_iso_10646_string, 
                                    std_macros.is_stdc_iso_10646_defined, 
                                    std_macros.stdc_iso_10646_integral);
    
    print_macro_definition_integral(outstream, 
                                    c_cpp_std_macro_ndebug_string, 
                                    std_macros.is_ndebug_defined, 
                                    std_macros.ndebug_integral);
}


#include <poc/poc_lang.h>
void print_lang(FILE* outstream)
{
    fprintf(outstream, "POC programming language detection");
    fprintf(outstream, "\n");
    
    fprintf(outstream, "  POC_LANG defined and set to ");
    
    switch (POC_LANG) 
    {
        case POC_LANG_C_C89_ID:
            fprintf(outstream, "POC_LANG_C_C89_ID");
            break;
        case POC_LANG_C_C99_ID:
            fprintf(outstream, "POC_LANG_C_C99_ID");
            break;
        case POC_LANG_C_UNKNOWN_ID:
            fprintf(outstream, "POC_LANG_C_UNKNOWN_ID");
            break;
        case POC_LANG_CPP_CPP98_ID:
            fprintf(outstream, "POC_LANG_CPP_CPP98_ID");
            break;
        case POC_LANG_CPP_UNKNOWN_ID:
            fprintf(outstream, "POC_LANG_CPP_UNKNOWN_ID");
            break;
        case POC_LANG_OBJC_UNKNOWN_ID:
            fprintf(outstream, "POC_LANG_OBJC_UNKNOWN_ID");
            break;
        case POC_LANG_OPENCL_UNKNOWN_ID:
            fprintf(outstream, "POC_LANG_OPENCL_UNKNOWN_ID");
            break;
        case POC_LANG_UNKNOWN_ID:
            fprintf(outstream, "POC_LANG_UNKNOWN_ID");
            break;
        default:
            fprintf(outstream, "non-POC predefined value of %d", POC_LANG);
    };
    fprintf(outstream, "\n");
    
    fprintf(outstream, "  POC_LANG_STRING defined and set to %s", POC_LANG_STRING);
    fprintf(outstream, "\n\n");
    
#if defined(POC_LANG_DISABLE_AUTODETECT)
    fprintf(outstream, "  POC_LANG_DISABLE_AUTODETECT defined");
    fprintf(stdout, "\n\n\n");
#endif
    
    
    
#if defined(POC_LANG_C)
    fprintf(outstream, "  POC_LANG_C defined and set to ");
    
    switch (POC_LANG_C)
    {
        case POC_LANG_C_C89_ID:
            fprintf(outstream, "POC_LANG_C_C89_ID");
            break;
        case POC_LANG_C_C99_ID:
            fprintf(outstream, "POC_LANG_C_C99_ID");
            break;
        case POC_LANG_C_UNKNOWN_ID:
            fprintf(outstream, "POC_LANC_C_UNKNOWN_ID");
            break;
        default:
            fprintf(outstream, "non-POC predefined value of %d", POC_LANG_C);
    };
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_LANG_C_C89)
    fprintf(outstream, "  POC_LANG_C_C89 defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_LANG_C_C99)
    fprintf(outstream, "  POC_LANG_C_C99 defined");
    fprintf(outstream, "\n");
#endif    
    
#if defined(POC_LANG_CPP)
    fprintf(outstream, "  POC_LANG_CPP defined and set to ");
    
    switch (POC_LANG_CPP)
    {
        case POC_LANG_CPP_CPP98_ID:
            fprintf(outstream, "POC_LANG_CPP_CPP98_ID");
            break;
        case POC_LANG_CPP_UNKNOWN_ID:
            fprintf(outstream, "POC_LANG_CPP_UNKNOWN_ID");
            break;
        default:
            fprintf(outstream, "non-POC predefined value of %d", POC_LANG_CPP);
    };
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_LANG_OBJC)
    fprintf(outstream, "  POC_LANG_OBJC defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_LANG_OPENCL)
    fprintf(outstream, "  POC_LANG_OPENCL defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_LANG_C_TYPE_BOOL_SUPPORT)
    fprintf(outstream, "  POC_LANG_C_TYPE_BOOL_SUPPORT defined");
    fprintf(outstream, "\n");
#endif

#if defined(POC_LANG_C_TYPE_LONG_LONG_SUPPORT)
    fprintf(outstream, "  POC_LANG_C_TYPE_LONG_LONG_SUPPORT defined");
    fprintf(outstream, "\n");
#endif

#if defined(POC_LANG_C_TYPE_LONG_DOUBLE_SUPPORT)
    fprintf(outstream, "  POC_LANG_C_TYPE_LONG_DOUBLE_SUPPORT defined");
    fprintf(outstream, "\n");
#endif

#if defined(POC_LANG_C_HEADER_STDBOOL_SUPPORT)
    fprintf(outstream, "  POC_LANG_C_HEADER_STDBOOL_SUPPORT defined");
    fprintf(outstream, "\n");
#endif

#if defined(POC_LANG_C_HEADER_STDINT_SUPPORT)
    fprintf(outstream, "  POC_LANG_C_HEADER_STDINT_SUPPORT defined");
    fprintf(outstream, "\n");
#endif

#if defined(POC_LANG_C_TYPE_COMPLEX_SUPPORT)
    fprintf(outstream, "  POC_LANG_C_TYPE_COMPLEX_SUPPORT defined");
    fprintf(outstream, "\n");
#endif

#if defined(POC_LANG_C_TYPE_IMAGINARY_SUPPORT)
    fprintf(outstream, "  POC_LANG_C_TYPE_IMAGINARY_SUPPORT defined");
    fprintf(outstream, "\n");
#endif

#if defined(POC_LANG_CPP_RTTI_SUPPORT)
    fprintf(outstream, "  POC_LANG_CPP_RTTI_SUPPORT defined");
    fprintf(outstream, "\n");
#endif

#if defined(POC_LANG_CPP_EXCEPTIONS_SUPPORT)
    fprintf(outstream, "  POC_LANG_CPP_EXCEPTIONS_SUPPORT defined");
    fprintf(outstream, "\n");
#endif
    
}

#include <poc/poc_data_model.h>

void print_data_model(FILE* outstream)
{
    fprintf(outstream, "POC data model detection");
    fprintf(outstream, "\n");
    
    fprintf(outstream, "  POC_DATA_MODEL defined and set to ");
    
    switch (POC_DATA_MODEL)
    {
        case POC_DATA_MODEL_LP32_ID:
            fprintf(outstream, "POC_DATA_MODEL_LP32_ID");
            break;
        case POC_DATA_MODEL_ILP32_ID:
            fprintf(outstream, "POC_DATA_MODEL_ILP32_ID");
            break;
        case POC_DATA_MODEL_LP64_ID:
            fprintf(outstream, "POC_DATA_MODEL_LP64_ID");
            break;
        case POC_DATA_MODEL_LLP64_ID:
            fprintf(outstream, "POC_DATA_MODEL_LLP64_ID");
            break;
        case POC_DATA_MODEL_ILP64_ID:
            fprintf(outstream, "POC_DATA_MODEL_ILP64_ID");
            break;
        case POC_DATA_MODEL_SILP64_ID:
            fprintf(outstream, "POC_DATA_MODEL_SILP64_ID");
            break;
        case POC_DATA_MODEL_UNKNOWN_ID:
            fprintf(outstream, "POC_DATA_MODEL_UNKNOWN_ID");
            break;
        default:
            fprintf(outstream, "non-POC predefined value of %d", POC_DATA_MODEL);
    };
    fprintf(outstream, "\n");
    
    fprintf(outstream, "  POC_DATA_MODEL_STRING defined set to %s", POC_DATA_MODEL_STRING);
    fprintf(outstream, "\n\n");

#if defined(POC_DATA_MODEL_DISABLE_AUTODETECT)
    fprintf(outstream, "  POC_DATA_MODEL_DISABLE_AUTODETECT defined");
    fprintf(stdout, "\n\n\n");
#endif
    
    
#if defined(POC_DATA_MODEL_LP32)
    fprintf(outstream, "  POC_DATA_MODEL_LP32 defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_DATA_MODEL_ILP32)
    fprintf(outstream, "  POC_DATA_MODEL_ILP32 defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_DATA_MODEL_LP64)
    fprintf(outstream, "  POC_DATA_MODEL_LP64 defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_DATA_MODEL_LLP64)
    fprintf(outstream, "  POC_DATA_MODEL_LLP64 defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_DATA_MODEL_ILP64)
    fprintf(outstream, "  POC_DATA_MODEL_ILP64 defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_DATA_MODEL_SILP64)
    fprintf(outstream, "  POC_DATA_MODEL_SILP64 defined");
    fprintf(outstream, "\n");
#endif
    
}

#include <poc/poc_compiler.h>
void print_compiler(FILE* outstream)
{
    fprintf(outstream, "POC comiler detection");
    fprintf(outstream, "\n");
    
    fprintf(outstream, "  POC_COMPILER defined and set to ");
    
    switch (POC_COMPILER)
    {
        case POC_COMPILER_GCC_ID:
            fprintf(outstream, "POC_COMPILER_GCC_ID");
            break;
        case POC_COMPILER_MSVC_ID:
            fprintf(outstream, "POC_COMPILER_MSVC_ID");
            break;
        case POC_COMPILER_NVCC_ID:
            fprintf(outstream, "POC_COMPILER_NVCC_ID");
            break;
        case POC_COMPILER_OPENCL_GENERIC_ID:
            fprintf(outstream, "POC_COMPILER_OPENCL_GENERIC_ID");
            break;
        case POC_COMPILER_ICC_ID:
            fprintf(outstream, "POC_COMPILER_ICC_ID");
            break;
        case POC_COMPILER_UNKNOWN_ID:
            fprintf(outstream, "POC_COMPILER_UNKNOWN_ID");
            break;
        default:
            fprintf(outstream, "non-POC predefined value of %d", POC_COMPILER);
    };
    fprintf(outstream, "\n");
    
    fprintf(outstream, "  POC_COMPILER_STRING defined and set to %s", POC_COMPILER_STRING);
    fprintf(outstream, "\n");
    fprintf(outstream, "  POC_COMPILER_VERSION defined and set to %i", POC_COMPILER_VERSION);
    fprintf(outstream, "\n\n");
    
#if defined(POC_COMPILER_DISABLE_AUTODETECT)
    fprintf(outstream, "  POC_COMPILER_DISABLE_AUTODETECT defined");
    fprintf(stdout, "\n\n\n");
#endif
    
#if defined(POC_COMPILER_GCC)
    fprintf(outstream, "  POC_COMPILER_GCC defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_COMPILER_MSVC)
    fprintf(outstream, "  POC_COMPILER_MSVC defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_COMPILER_NVCC)
    fprintf(outstream, "  POC_COMPILER_NVCC defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_COMPILER_OPENCL_GENERIC)
    fprintf(outstream, "  POC_COMPILER_OPENCL_GENERIC defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_COMPILER_ICC)
    fprintf(outstream, "  POC_COMPILER_ICC defined");
    fprintf(outstream, "\n");
    
    fprintf(outstream, "  POC_COMPILER_ICC_HOST defined and set to ");
    
    switch (POC_COMPILER_ICC_HOST)
    {
        case POC_COMPILER_GCC_ID:
            fprintf(outstream, "POC_COMPILER_GCC_ID");
            break;
        case POC_COMPILER_MSVC_ID:
            fprintf(outstream, "POC_COMPILER_MSVC_ID");
            break;
        case POC_COMPILER_UNKNOWN_ID:
            fprintf(outstream, "POC_COMPILER_UNKNOWN_ID");
            break;
        default:
            fprintf(outstream, "non-POC predefined value of %d", POC_COMPILER_ICC_HOST);
    };
    fprintf(outstream, "\n");
    
    fprintf(outstream, "  POC_COMPILER_ICC_HOST_STRING defined and set to %s", POC_COMPILER_ICC_HOST_STRING);
    fprintf(outstream, "\n");
    fprintf(outstream, "  POC_COMPILER_ICC_HOST_VERSION defined and set to %i", POC_COMPILER_ICC_HOST_VERSION);
    fprintf(outstream, "\n");
    
#if     defined(POC_COMPILER_ICC_HOST_GCC)
    fprintf(outstream, "  POC_COMPILER_ICC_HOST_GCC defined");
    fprintf(outstream, "\n");
#       endif
  
#if     defined(POC_COMPILER_ICC_HOST_MSVC)
    fprintf(outstream, "  POC_COMPILER_ICC_HOST_MSVC defined");
    fprintf(outstream, "\n");
#       endif
    
#if     defined(POC_COMPILER_ICC_HOST_UNKNOWN)
    fprintf(outstream, "  POC_COMPILER_ICC_HOST_UNKNOWN defined");
    fprintf(outstream, "\n");
#       endif
    
#endif
    
#if defined(POC_COMPILER_UNKNWON)
    fprintf(outstream, "  POC_COMPILER_UNKNOWN defined");
    fprintf(outstream, "\n");
#endif
    
}

#include <poc/poc_arch.h>
void print_arch(FILE* outstream)
{
    fprintf(outstream, "POC machine architecture detection");
    fprintf(outstream, "\n");
    
    fprintf(outstream, "  POC_ARCH defined and set to ");
    
    switch (POC_ARCH)
    {
        case POC_ARCH_X86_32_ID:
            fprintf(outstream, "POC_ARCH_X86_32_ID");
            break;
        case POC_ARCH_X86_64_ID:
            fprintf(outstream, "POC_ARCH_X86_64_ID");
            break;
        case POC_ARCH_PPC_ID:
            fprintf(outstream, "POC_ARCH_PPC_ID");
            break;
        case POC_ARCH_PPC64_ID:
            fprintf(outstream, "POC_ARCH_PPC64_ID");
            break;
        case POC_ARCH_ARM_ID:
            fprintf(outstream, "POC_ARCH_ARM_ID");
            break;
        case POC_ARCH_ARM_THUMB_ID:
            fprintf(outstream, "POC_ARCH_ARM_THUMB_ID");
            break;
        case POC_ARCH_UNKNOWN_ID:
            fprintf(outstream, "POC_ARCH_UNKNOWN_ID");
            break;
        default:
            fprintf(outstream, "non-POC predefined value of %d", POC_ARCH);
    };
    fprintf(outstream, "\n");
    
    fprintf(outstream, "  POC_ARCH_STRING defined and set to %s", POC_ARCH_STRING);
    fprintf(outstream, "\n\n");
    
#if defined(POC_ARCH_DISABLE_AUTODETECT)
    fprintf(outstream, "  POC_ARCH_DISABLE_AUTODETECT defined");
    fprintf(stdout, "\n\n\n");
#endif
    
    
#if defined(POC_ARCH_X86)
    fprintf(outstream, "  POC_ARCH_X86 defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_ARCH_X86_32)
    fprintf(outstream, "  POC_ARCH_X86_32 defined");
    fprintf(outstream, "\n");
#endif
  
#if defined(POC_ARCH_X86_64)
    fprintf(outstream, "  POC_ARCH_X86_64 defined");
    fprintf(outstream, "\n");
#endif
  
#if defined(POC_ARCH_PPC)
    fprintf(outstream, "  POC_ARCH_PPC defined");
    fprintf(outstream, "\n");
#endif
  
#if defined(POC_ARCH_PPC64)
    fprintf(outstream, "  POC_ARCH_PPC64 defined");
    fprintf(outstream, "\n");
#endif
  
#if defined(POC_ARCH_ARM)
    fprintf(outstream, "  POC_ARCH_ARM defined");
    fprintf(outstream, "\n");
#endif
  
#if defined(POC_ARCH_ARM_THUMB)
    fprintf(outstream, "  POC_ARCH_ARM_THUMB defined");
    fprintf(outstream, "\n");
#endif
  
#if defined(POC_ARCH_UNKNOWN)
    fprintf(outstream, "  POC_ARCH_UNKNOWN defined");
    fprintf(outstream, "\n");
#endif
    
}

#include <poc/poc_endian.h>
void print_endian(FILE* outstream)
{
    fprintf(outstream, "POC machine endianess detection");
    fprintf(outstream, "\n");
    
    fprintf(outstream, "  POC_ENDIAN defined and set to ");
    
    switch (POC_ENDIAN)
    {
        case POC_ENDIAN_LITTLE_ID:
            fprintf(outstream, "POC_ENDIAN_LITTLE_ID");
            break;
        case POC_ENDIAN_BIG_ID:
            fprintf(outstream, "POC_ENDIAN_BIG_ID");
            break;
        case POC_ENDIAN_UNKNOWN_ID:
            fprintf(outstream, "POC_ENDIAN_UNKNOWN_ID");
            break;
        default:
            fprintf(outstream, "non-POC predefined value of %d", POC_ENDIAN);
    };
    fprintf(outstream, "\n");
    
    fprintf(outstream, "  POC_ENDIAN_STRING defined and set to %s", POC_ENDIAN_STRING);
    fprintf(outstream, "\n\n");
    
#if defined(POC_ENDIAN_DISABLE_AUTODETECT)
    fprintf(outstream, "  POC_ENDIAN_DISABLE_AUTODETECT defined");
    fprintf(stdout, "\n\n\n");
#endif
    
#if defined(POC_ENDIAN_LITTLE)
    fprintf(outstream, "  POC_ENDIAN_LITTLE defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_ENDIAN_BIG)
    fprintf(outstream, "  POC_ENDIAN_BIG defined");
    fprintf(outstream, "\n");
#endif
  
#if defined(POC_ENDIAN_UNKNOWN)
    fprintf(outstream, "  POC_ENDIAN_UNKNOWN defined");
    fprintf(outstream, "\n");
#endif
    
}

#include <poc/poc_os.h>
void print_os(FILE* outstream)
{
    fprintf(outstream, "POC operating system detection");
    fprintf(outstream, "\n");
    
    fprintf(outstream, "  POC_OS defined and set to ");
    
    switch (POC_OS)
    {
        case POC_OS_UNIX_ID:
            fprintf(outstream, "POC_OS_UNIX_ID");
            break;
        case POC_OS_MACOSX_ID:
            fprintf(outstream, "POC_OS_MACOSX_ID");
            break;
        case POC_OS_LINUX_ID:
            fprintf(outstream, "POC_OS_LINUX_ID");
            break;
        case POC_OS_WIN32_ID:
            fprintf(outstream, "POC_OS_WIN32_ID");
            break;
        case POC_OS_WIN64_ID:
            fprintf(outstream, "POC_OS_WIN64_ID");
            break;
        case POC_OS_UNKNOWN_ID:
            fprintf(outstream, "POC_OS_UNKNOWN_ID");
            break;
        default:
            fprintf(outstream, "non-POC predefined value of %d", POC_OS);
    };
    fprintf(outstream, "\n");
    
    fprintf(outstream, "  POC_OS_STRING defined and set to %s", POC_OS_STRING);
    fprintf(outstream, "\n\n");
    
#if defined(POC_OS_DISABLE_AUTODETECT)
    fprintf(outstream, "  POC_OS_DISABLE_AUTODETECT defined");
    fprintf(stdout, "\n\n\n");
#endif
    
#if defined(POC_OS_UNIX)
    fprintf(outstream, "  POC_OS_UNIX defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_OS_MACOSX)
    fprintf(outstream, "  POC_OS_MACOSX defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_OS_LINUX)
    fprintf(outstream, "  POC_OS_LINUX defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_OS_WIN32)
    fprintf(outstream, "  POC_OS_WIN32 defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_OS_WIN64)
    fprintf(outstream, "  POC_OS_WIN64 defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_OS_UNKNOWN)
    fprintf(outstream, "  POC_OS_UNKNOWN defined");
    fprintf(outstream, "\n");
#endif
    
}


int main(int argc, char* argv[])
{
    // Prevent warning that argument isn't used.
    (void)argc;
    
    // Print the app-name.
    fprintf(stdout, "%s \n\n", argv[0]);
    
    print_std_predefined_macros(stdout);
    fprintf(stdout, "\n");
            
#if defined(POC_DISABLE_AUTODETECT)
    fprintf(outstream, "POC_DISABLE_AUTODETECT defined");
    fprintf(stdout, "\n");
#endif
    
    print_lang(stdout);
    fprintf(stdout, "\n");
    
    print_data_model(stdout);
    fprintf(stdout, "\n");
    
    print_compiler(stdout);
    fprintf(stdout, "\n");
    
    print_arch(stdout);
    fprintf(stdout, "\n");
    
    print_endian(stdout);
    fprintf(stdout, "\n");
            
    print_os(stdout);
    
    return EXIT_SUCCESS;
}

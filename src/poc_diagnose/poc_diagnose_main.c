/*
 * Copyright (c) 2009, Bjoern Knafla
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this 
 *   list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice, 
 *   this list of conditions and the following disclaimer in the documentation 
 *   and/or other materials provided with the distribution.
 * - Neither the name of the Bjoern Knafla nor the names of its contributors may 
 *   be used to endorse or promote products derived from this software without 
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 *
 * App that outputs POC's compile time target configuration to stdout.
 *
 * Code is an example how to possibly use POC's macros.
 *
 * @attention Code is only compilable with hosted C version that offer the
 *            headers used below and won't work on OpenCL or CUDA devices.
 *
 * @todo TODO: Enable platform detection on OpenCL or CUDA devices by only collecting
 *       which settings are enabled like it is done for standard preprocessor
 *       defines instead of printing them directly to stdout. Then add a host
 *       app that takes the collected data and finally prints it to stdout.
 */

/* Include EXIT_SUCCESS
 */
#include <stdlib.h>

/* Include stdout, fprintf, FILE
 */
#include <stdio.h>

/* Include POC macros to detect target platform configuration.
 */
#include <poc/poc.h>

/* Include @c POC_STRINGIZE */
#include <poc/poc_preprocessor_utilities.h>

/* Include poc_tests_execute */
#include "poc_tests.h"

/**
 * name: String constants describing standard preprocessor defined macros.
 */
/*@{*/
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
/*@}*/


/**
 * Struct to collect settings of standard preprocessor macros, if they are
 * defined or undefined, and which value they carry.
 *
 * Created by @c make_std_c_cpp_predefined_macros .
 */
typedef struct std_c_cpp_predefined_macros
    {
        /** @c 0 if @c __DATA__ isn't defined, otherwise unequal to @c 0 */
        int is_date_defined;
        /** Value of @c __DATA__ if defined, otherwise @c 0. */
        char const* date_string;
        
        /** @c 0 if @c __TIME__ isn't defined, otherwise unequal to @c 0 */
        int is_time_defined;
        /** Value of @c __TIME__ if defined, otherwise @c 0. */
        char const* time_string;
        
        /** @c 0 if @c __FILE__ isn't defined, otherwise unequal to @c 0 */
        int is_file_defined;
        /** Value of @c __FILE__ if defined, otherwise @c 0. */
        char const* file_string;
        
        /** @c 0 if @c __LINE__ isn't defined, otherwise unequal to @c 0 */
        int is_line_defined;
        /** Value of @c __LINE__ if defined, otherwise @c 0. */
        long line_integral;
        
        /** @c 0 if @c __cplusplus isn't defined, otherwise unequal to @c 0 */
        int is_cplusplus_defined;
        /** Value of @c __cplusplus if defined, otherwise @c 0. */
        long cplusplus_integral;
        
        /** @c 0 if @c __STDC__ isn't defined, otherwise unequal to @c 0 */
        int is_stdc_defined;
        /** Value of @c __STDC__ if defined, otherwise @c 0. */
        long stdc_integral;
        
        /** @c 0 if @c __STDC_HOSTED__ isn't defined, otherwise unequal to @c 0 */
        int is_stdc_hosted_defined;
        /** Value of @c __STDC_HOSTED__ if defined, otherwise @c 0. */
        long stdc_hosted_integral;
        
        /** @c 0 if @c __STDC_VERSION__ isn't defined, otherwise unequal to @c 0 */
        int is_stdc_version_defined;
        /** Value of @c __STDC_VERSION__ if defined, otherwise @c 0. */
        long stdc_version_integral;
        
        /** @c 0 if @c __STDC_IEC_559__ isn't defined, otherwise unequal to @c 0 */
        int is_stdc_iec_559_defined;
        /** Value of @c __STDC_IEC_559__ if defined, otherwise @c 0. */
        long stdc_iec_559_integral;
        
        /** @c 0 if @c __STDC_IEC_559_COMPLEX__ isn't defined, otherwise unequal to @c 0 */
        int is_stdc_iec_559_complex_defined;
        /** Value of @c __STDC_IEC_559_COMPLEX__ if defined, otherwise @c 0. */
        long stdc_iec_559_complex_integral;
        
        /** @c 0 if @c __STDC_ISO_10646__ isn't defined, otherwise unequal to @c 0 */
        int is_stdc_iso_10646_defined;
        /** Value of @c __STDC_ISO_10646__ if defined, otherwise @c 0. */
        long stdc_iso_10646_integral;
        
        /** @c 0 if @c NDEBUG isn't defined, otherwise unequal to @c 0 */
        int is_ndebug_defined;
        /** Value of @c NDEBUG if defined, otherwise @c 0. */
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
void print_primary_types(FILE* outstream);


/**
 * Main.
 */
int main(int argc, char* argv[])
{
    /* Prevent warning that argument isn't used.
     */
    (void)argc;
    (void)argv;
    
    /* Print the app-name.
     */
    fprintf(stdout, "%s \n\n", "POC Diagnose");
    
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
    fprintf(stdout, "\n");
    
    print_primary_types(stdout);
    
    
#define TEST_COUNT 2
    int test_results[TEST_COUNT] = {0};
    poc_tests_execute(test_results, TEST_COUNT);
    
    
    
    return EXIT_SUCCESS;
}


/**
 * Creates instances of @c std_c_cpp_predefined_macros based on the 
 * C/C++/Objective-C standard preprocessor macros set at compile-time.
 */
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
    
#if defined(__STDC_HOSTED__)
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

/**
 * Prints to @a outstream if the macro @c macro_description_string is defined
 * or not and if it is defined also prints its value.
 */
int print_macro_definition_string(FILE* outstream, 
                                  char const* macro_description_string, 
                                  int is_macro_defined, 
                                  char const* value_string)
{
    int chars_written = 0;
    int const chars_written_description = fprintf(outstream, "  %s ", macro_description_string);
    int chars_written_newline = 0;
    
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
    
    chars_written_newline = fprintf(outstream, "\n");
    
    if (0 > chars_written_newline)
    {
        return chars_written_newline;
    }
    
    chars_written += chars_written_newline;
    
    
    return chars_written;
}


/**
 * Prints to @a outstream if the macro @c macro_description_string is defined
 * or not and if it is defined also prints its value.
 */
int print_macro_definition_integral(FILE* outstream, 
                                    char const* macro_description_string, 
                                    int is_macro_defined, 
                                    long value_integral)
{
    int chars_written = 0;
    int const chars_written_description = fprintf(outstream, "  %s ", macro_description_string);
    int chars_written_newline = 0;
    
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
    
    chars_written_newline = fprintf(outstream, "\n");
    
    if (0 > chars_written_newline)
    {
        return chars_written_newline;
    }
    
    chars_written += chars_written_newline;
    
    
    return chars_written;
}

/**
 * Prints for all standard preprocessor macros if they are defined or undefined
 * and if they are defined which value they hold.
 */
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

/**
 * Print (most) defined @c POC_LANG related macros and their values to 
 * @a outstream.
 */
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
        case POC_LANG_OPENCL_OPENCL0100_ID:
            fprintf(outstream, "POC_LANG_OPENCL_OPENCL0100_ID");
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
        case POC_LANG_OPENCL_OPENCL0100_ID:
            fprintf(outstream, "POC_LANG_OPENCL_OPENCL0100_ID");
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
    fprintf(outstream, "  POC_LANG_OPENCL defined and set to ");
    
    switch (POC_LANG_OPENCL)
    {
        case POC_LANG_OPENCL_OPENCL0100_ID:
            fprintf(outstream, "POC_LANG_OPENCL_OPENCL0100_ID");
            break;
        case POC_LANG_OPENCL_UNKNOWN_ID:
            fprintf(outstream, "POC_LANG_OPENCL_UNKNOWN_ID");
            break;
        default:
           fprintf(outstream, "non-POC predefined value of %d", POC_LANG_OPENCL); 
    };
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_LANG_OPENCL_OPENCL0100)
    fprintf(outstream, "  POC_LANG_OPENCL_OPENCL0100 defined");
    fprintf(outstream, "\n");
#endif 
    
#if defined(POC_LANG_OPENCL_UNKNOWN)
    fprintf(outstream, "  POC_LANG_OPENCL_UNKNOWN defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_LANG_OPENCL_EMBEDDED_PROFILE)
    fprintf(outstream, "  POC_LANG_OPENCL_EMBEDDED_PROFILE defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_LANG_OPENCL_IMAGE_SUPPORT)
    fprintf(outstream, "  POC_LANG_OPENCL_IMAGE_SUPPORT defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_LANG_OPENCL_FAST_RELAXED_MATH)
    fprintf(outstream, "  POC_LANG_OPENCL_ROUNDING_MODE defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_LANG_OPENCL_DEVICE_ADDRESS_SPACE)
    fprintf(outstream, "  POC_LANG_OPENCL_DEVICE_ADDRESS_SPACE set to %s", POC_STRINGIZE(POC_LANG_OPENCL_DEVICE_ADDRESS_SPACE));
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_LANG_OPENCL_ROUNDING_MODE)
    fprintf(outstream, "  POC_LANG_OPENCL_ROUNDING_MODE set to %s", POC_STRINGIZE(POC_LANG_OPENCL_ROUNDING_MODE));
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
    
#if defined(POC_LANG_C_HEADER_STDBOOL_SUPPORT)
    fprintf(outstream, "  POC_LANG_C_HEADER_STDBOOL_SUPPORT defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_LANG_C_HEADER_STDINT_SUPPORT)
    fprintf(outstream, "  POC_LANG_C_HEADER_STDINT_SUPPORT defined");
    fprintf(outstream, "\n");
#endif
   
#if defined(POC_LANG_C_HEADER_INTTYPES_SUPPORT)
    fprintf(outstream, "  POC_LANG_C_HEADER_INTTYPES_SUPPORT defined");
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
    
    
#if defined(POC_LANG_CPP_TYPE_LONG_LONG_SUPPORT)
    fprintf(outstream, "  POC_LANG_CPP_TYPE_LONG_LONG_SUPPORT defined");
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


/**
 * Print (most) defined @c POC_DATA_MODEL related macros and their values to 
 * @a outstream.
 */
void print_data_model(FILE* outstream)
{
    fprintf(outstream, "POC data model detection");
    fprintf(outstream, "\n");
    
    fprintf(outstream, "  POC_DATA_MODEL defined and set to ");
    
    switch (POC_DATA_MODEL)
    {
        case POC_DATA_MODEL_IP32_ID:
            fprintf(outstream, "POC_DATA_MODEL_IP32_ID");
            break;
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
    
  
#if defined(POC_DATA_MODEL_IP32)
    fprintf(outstream, "  POC_DATA_MODEL_IP32 defined");
    fprintf(outstream, "\n");
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


/**
 * Print (most) defined @c POC_COMPILER related macros and their values to 
 * @a outstream.
 */
void print_compiler(FILE* outstream)
{
    fprintf(outstream, "POC compiler detection");
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
    fprintf(outstream, "  POC_COMPILER_VERSION defined and set to %ld", POC_COMPILER_VERSION);
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

/**
 * Print (most) defined @c POC_ARCH related macros and their values to 
 * @a outstream.
 */
void print_arch(FILE* outstream)
{
    fprintf(outstream, "POC machine architecture detection");
    fprintf(outstream, "\n");
    
    fprintf(outstream, "  POC_ARCH defined and set to ");
    
    switch (POC_ARCH)
    {
        case POC_ARCH_X86_ID:
            fprintf(outstream, "POC_ARCH_X86_ID");
            break;
        case POC_ARCH_X86_32_ID:
            fprintf(outstream, "POC_ARCH_X86_32_ID");
            break;
        case POC_ARCH_X86_64_ID:
            fprintf(outstream, "POC_ARCH_X86_64_ID");
            break;
        case (POC_ARCH_X86_ID | POC_ARCH_X86_32_ID):
            fprintf(outstream, "POC_ARCH_X86_ID | POC_ARCH_X86_32_ID");
            break;
        case (POC_ARCH_X86_ID | POC_ARCH_X86_64_ID):
            fprintf(outstream, "POC_ARCH_X86_ID | POC_ARCH_X86_64_ID");
            break;    
        case POC_ARCH_PPC_ID:
            fprintf(outstream, "POC_ARCH_PPC_ID");
            break;
        case POC_ARCH_PPC64_ID:
            fprintf(outstream, "POC_ARCH_PPC64_ID");
            break;
        case (POC_ARCH_PPC_ID | POC_ARCH_PPC64_ID):
            fprintf(outstream, "POC_ARCH_PPC_ID | POC_ARCH_PPC64_ID");
            break;
        case POC_ARCH_CELL_PPU_ID:
            fprintf(outstream, "POC_ARCH_CELL_PPU_ID");
            break;
        case (POC_ARCH_PPC_ID | POC_ARCH_PPC64_ID | POC_ARCH_CELL_PPU_ID):
            fprintf(outstream, "POC_ARCH_PPC_ID | POC_ARCH_PPC64_ID | POC_ARCH_CELL_PPU_ID");
            break;
        case POC_ARCH_CELL_SPU_ID:
            fprintf(outstream, "POC_ARCH_CELL_SPU_ID");
            break;
        case POC_ARCH_CELL_SPU_EDP_ID:
            fprintf(outstream, "POC_ARCH_CELL_SPU_EDP_ID");
            break;
        case (POC_ARCH_CELL_SPU_ID | POC_ARCH_CELL_SPU_EDP_ID):
            fprintf(outstream, "POC_ARCH_CELL_SPU_ID | POC_ARCH_CELL_SPU_EDP_ID");
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
    
#if defined(POC_ARCH_CELL_PPU)
    fprintf(outstream, "  POC_ARCH_CELL_PPU defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_ARCH_CELL_SPU)
    fprintf(outstream, "  POC_ARCH_CELL_SPU defined");
    fprintf(outstream, "\n");
#endif
 
#if defined(POC_ARCH_CELL_SPU_EDP)
    fprintf(outstream, "  POC_ARCH_CELL_SPU_EDP defined");
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_ARCH_UNKNOWN)
    fprintf(outstream, "  POC_ARCH_UNKNOWN defined");
    fprintf(outstream, "\n");
#endif
    
}

/**
 * Print (most) defined @c POC_ENDIAN related macros and their values to 
 * @a outstream.
 */
void print_endian(FILE* outstream)
{
    fprintf(outstream, "POC machine endienness detection");
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


/**
 * Print (most) defined @c POC_OS related macros and their values to 
 * @a outstream.
 */
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

/**
 * Print the defines for POC primary type macros.
 */
void print_primary_types(FILE* outstream)
{
    fprintf(outstream, "POC primary types definitions");
    fprintf(outstream, "\n");    
    
#if defined(POC_LONG_LONG)
    fprintf(outstream, "  POC_LONG_LONG set to %s", POC_STRINGIZE(POC_LONG_LONG));
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_UNSIGNED_LONG_LONG)
    fprintf(outstream, "  POC_UNSIGNED_LONG_LONG set to %s", POC_STRINGIZE(POC_UNSIGNED_LONG_LONG));
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_LONG_DOUBLE)
    fprintf(outstream, "  POC_LONG_DOUBLE set to %s", POC_STRINGIZE(POC_LONG_DOUBLE));
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_BOOL)
    fprintf(outstream, "  POC_BOOL set to %s", POC_STRINGIZE(POC_BOOL));
    fprintf(outstream, "\n");
    fprintf(outstream, "  POC_TRUE set to %s", POC_STRINGIZE(POC_TRUE));
    fprintf(outstream, "\n");
    fprintf(outstream, "  POC_FALSE set to %s", POC_STRINGIZE(POC_FALSE));
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_CHAR)
    fprintf(outstream, "  POC_CHAR set to %s", POC_STRINGIZE(POC_CHAR));
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_SIGNED_CHAR)
    fprintf(outstream, "  POC_SIGNED_CHAR set to %s", POC_STRINGIZE(POC_SIGNED_CHAR));
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_UNSIGNED_CHAR)
    fprintf(outstream, "  POC_UNSIGNED_CHAR set to %s", POC_STRINGIZE(POC_UNSIGNED_CHAR));
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_BYTE)
    fprintf(outstream, "  POC_BYTE set to %s", POC_STRINGIZE(POC_BYTE));
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_INT8)
    fprintf(outstream, "  POC_INT8 set to %s", POC_STRINGIZE(POC_INT8));
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_UINT8)
    fprintf(outstream, "  POC_UINT8 set to %s", POC_STRINGIZE(POC_UINT8));
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_INT16)
    fprintf(outstream, "  POC_INT16 set to %s", POC_STRINGIZE(POC_INT16));
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_UINT16)
    fprintf(outstream, "  POC_UINT16 set to %s", POC_STRINGIZE(POC_UINT16));
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_INT32)
    fprintf(outstream, "  POC_INT32 set to %s", POC_STRINGIZE(POC_INT32));
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_UINT32)
    fprintf(outstream, "  POC_UINT32 set to %s", POC_STRINGIZE(POC_UINT32));
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_INT64)
    fprintf(outstream, "  POC_INT64 set to %s", POC_STRINGIZE(POC_INT64));
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_UINT64)
    fprintf(outstream, "  POC_UINT64 set to %s", POC_STRINGIZE(POC_UINT64));
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_FLOAT32)
    fprintf(outstream, "  POC_FLOAT32 set to %s", POC_STRINGIZE(POC_FLOAT32));
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_FLOAT64)
    fprintf(outstream, "  POC_FLOAT64 set to %s", POC_STRINGIZE(POC_FLOAT64));
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_INTPTR_T)
    fprintf(outstream, "  POC_INTPTR_T set to %s", POC_STRINGIZE(POC_INTPTR_T));
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_UINTPTR_T)
    fprintf(outstream, "  POC_UINTPTR_T set to %s", POC_STRINGIZE(POC_UINTPTR_T));
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_PTRDIFF_T)
    fprintf(outstream, "  POC_PTRDIFF_T set to %s", POC_STRINGIZE(POC_PTRDIFF_T));
    fprintf(outstream, "\n");
#endif
    
#if defined(POC_SIZE_T)
    fprintf(outstream, "  POC_SIZE_T set to %s", POC_STRINGIZE(POC_SIZE_T));
    fprintf(outstream, "\n");
#endif

    
}


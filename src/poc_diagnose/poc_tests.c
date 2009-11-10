
#include "poc_tests.h"


/* Include CHAR_BIT */
#include <limits.h>

/* Include calloc, free */
#include <stdlib.h>

#include <assert.h>


#include <poc/poc_primary_types.h>
#include <poc/poc_data_model.h>
#include <poc/poc_preprocessor_utilities.h>


#define CHECK_SIZE(Type, ExpectedSize) (sizeof(Type) * CHAR_BIT == ExpectedSize)
#define CHECK_SIGNED(Type, Result) { Type a = (Type)~((size_t)0) ; Result = (a < (Type)0); }
#define CHECK_UNSIGNED(Type, Result) { Type a = (Type)~((size_t)0) ; Result = (a > (Type)0); }



typedef int (*test_func_f)(void);

/* Creating tests with preprocessor macros.
int poc_byte_size_8_test(void);
int poc_byte_size_8_test(void)
{
    return CHECK_SIZE(POC_BYTE,8);
}

int poc_byte_is_unsigned_test(void);
int poc_byte_is_unsigned_test(void)
{
    int is_unsigned = 0;
    CHECK_UNSIGNED(POC_BYTE, is_unsigned);
    return is_unsigned;
}
*/


#define CREATE_CHECK_SIZE_AND_SIGNED(Type, ExpectedSize) \
int Type##_size_##ExpectedSize##_test(void); \
int Type##_size_##ExpectedSize##_test(void) \
{ \
    return CHECK_SIZE(Type,ExpectedSize); \
} \
int Type##_is_signed_test(void); \
int Type##_is_signed_test(void) \
{ \
    int is_signed = 0; \
    CHECK_SIGNED(Type,is_signed); \
    return is_signed; \
}

#define CREATE_CHECK_SIZE_AND_UNSIGNED(Type, ExpectedSize) \
int Type##_size_##ExpectedSize##_test(void); \
int Type##_size_##ExpectedSize##_test(void) \
{ \
    return CHECK_SIZE(Type,ExpectedSize); \
} \
int Type##_is_unsigned_test(void); \
int Type##_is_unsigned_test(void) \
{ \
    int is_unsigned = 0; \
    CHECK_UNSIGNED(Type,is_unsigned); \
    return is_unsigned; \
}


#define CREATE_TEST_ENTRIES_SIZE_AND_SIGNED(Type,ExpectedSize) \
{ \
    POC_STRINGIZE(Type##_size_##ExpectedSize##_test), \
    Type##_size_##ExpectedSize##_test \
}, \
{ \
    POC_STRINGIZE(Type##_is_signed_test), \
    Type##_is_signed_test \
}

#define CREATE_TEST_ENTRIES_SIZE_AND_UNSIGNED(Type,ExpectedSize) \
{ \
    POC_STRINGIZE(Type##_size_##ExpectedSize##_test), \
    Type##_size_##ExpectedSize##_test \
}, \
{ \
    POC_STRINGIZE(Type##_is_unsigned_test), \
    Type##_is_unsigned_test \
}


#if defined(POC_BYTE)
CREATE_CHECK_SIZE_AND_UNSIGNED(POC_BYTE,8)
#endif

#if defined(POC_INT8)
CREATE_CHECK_SIZE_AND_SIGNED(POC_INT8,8)
#endif

#if defined(POC_UINT8)
CREATE_CHECK_SIZE_AND_UNSIGNED(POC_UINT8,8)
#endif

#if defined(POC_INT16)
CREATE_CHECK_SIZE_AND_SIGNED(POC_INT16,16)
#endif

#if defined(POC_UINT16)
CREATE_CHECK_SIZE_AND_UNSIGNED(POC_UINT16,16)
#endif

#if defined(POC_INT32)
CREATE_CHECK_SIZE_AND_SIGNED(POC_INT32,32)
#endif

#if defined(POC_UINT32)
CREATE_CHECK_SIZE_AND_UNSIGNED(POC_UINT32,32)
#endif

#if defined(POC_INT64)
CREATE_CHECK_SIZE_AND_SIGNED(POC_INT64,64)
#endif

#if defined(POC_UINT64)
CREATE_CHECK_SIZE_AND_UNSIGNED(POC_UINT64,64)
#endif

#if defined(POC_FLOAT32)
int POC_FLOAT32_size_32_test(void);
int POC_FLOAT32_size_32_test(void)
{
    return CHECK_SIZE(POC_FLOAT32,32);
}
#endif

#if defined(POC_FLOAT64)
int POC_FLOAT64_size_64_test(void);
int POC_FLOAT64_size_64_test(void)
{
    return CHECK_SIZE(POC_FLOAT64,64);
}
#endif



#if defined(POC_DATA_MODEL_IP32) || defined(POC_DATA_MODEL_LP32) || defined(POC_DATA_MODEL_ILP32)
#   define REQUIRED_POINTER_BIT_SIZE 32
#elif defined(POC_DATA_MODEL_LP64) || defined(POC_DATA_MODEL_LLP64) || defined(POC_DATA_MODEL_ILP64) || defined(POC_DATA_MODEL_SILP64)
#   define REQUIRED_POINTER_BIT_SIZE 64
#else
#   error Unknown pointer bit size.
#endif


#if defined(POC_INTPTR_T)
CREATE_CHECK_SIZE_AND_SIGNED(POC_INTPTR_T,REQUIRED_POINTER_BIT_SIZE)
#endif

#if defined(POC_UINTPTR_T)
CREATE_CHECK_SIZE_AND_UNSIGNED(POC_UINTPTR_T,REQUIRED_POINTER_BIT_SIZE)
#endif

#if defined(POC_PTRDIFF_T)
CREATE_CHECK_SIZE_AND_SIGNED(POC_PTRDIFF_T,REQUIRED_POINTER_BIT_SIZE)
#endif

#if defined(POC_SIZE_T)
CREATE_CHECK_SIZE_AND_UNSIGNED(POC_SIZE_T,REQUIRED_POINTER_BIT_SIZE)
#endif



struct test_s {
    char const* name;
    test_func_f function;
};


static struct test_s tests[] = {

#if defined(POC_BYTE)
    CREATE_TEST_ENTRIES_SIZE_AND_UNSIGNED(POC_BYTE,8),
#endif
    
#if defined(POC_INT8)
    CREATE_TEST_ENTRIES_SIZE_AND_SIGNED(POC_INT8,8),
#endif
    
#if defined(POC_UINT8)
    CREATE_TEST_ENTRIES_SIZE_AND_UNSIGNED(POC_UINT8,8),
#endif
    
#if defined(POC_INT16)
    CREATE_TEST_ENTRIES_SIZE_AND_SIGNED(POC_INT16,16),
#endif
    
#if defined(POC_UINT16)
    CREATE_TEST_ENTRIES_SIZE_AND_UNSIGNED(POC_UINT16,16),
#endif
    
#if defined(POC_INT32)
    CREATE_TEST_ENTRIES_SIZE_AND_SIGNED(POC_INT32,32),
#endif
    
#if defined(POC_UINT32)
    CREATE_TEST_ENTRIES_SIZE_AND_UNSIGNED(POC_UINT32,32),
#endif
    
#if defined(POC_INT64)
    CREATE_TEST_ENTRIES_SIZE_AND_SIGNED(POC_INT64,64),
#endif
    
#if defined(POC_UINT64)
    CREATE_TEST_ENTRIES_SIZE_AND_UNSIGNED(POC_UINT64,64),
#endif
    
#if defined(POC_FLOAT32)
    {
        "POC_FLOAT32_size_32_test",
        POC_FLOAT32_size_32_test
    },
#endif
    
#if defined(POC_FLOAT64)
    {
        "POC_FLOAT64_size_64_test",
        POC_FLOAT64_size_64_test
    },
#endif
    
#if defined(POC_INTPTR_T)
    CREATE_TEST_ENTRIES_SIZE_AND_SIGNED(POC_INTPTR_T,REQUIRED_POINTER_BIT_SIZE),
#endif
    
#if defined(POC_UINTPTR_T)
    CREATE_TEST_ENTRIES_SIZE_AND_UNSIGNED(POC_UINTPTR_T,REQUIRED_POINTER_BIT_SIZE),
#endif  
    
#if defined(POC_PTRDIFF_T)
    CREATE_TEST_ENTRIES_SIZE_AND_SIGNED(POC_PTRDIFF_T,REQUIRED_POINTER_BIT_SIZE),
#endif
    
#if defined(POC_SIZE_T)
    CREATE_TEST_ENTRIES_SIZE_AND_UNSIGNED(POC_SIZE_T,REQUIRED_POINTER_BIT_SIZE),
#endif 
};






void poc_tests_print_all(FILE* outstream)
{
    size_t number_of_tests;
    int return_code;
    int *test_results;
    
    
    number_of_tests = poc_tests_test_count();
    
    test_results = (int*)calloc(number_of_tests, sizeof(int));
    
    
    
    number_of_tests = poc_tests_execute(test_results, number_of_tests);
    return_code = poc_tests_print_results(outstream, 
                                          test_results, 
                                          number_of_tests);
    
    assert(EINVAL != return_code);
    
    free(test_results);
}



size_t poc_tests_test_count(void)
{
    return sizeof(tests)/sizeof(struct test_s);
}


char const* poc_tests_name_of_test(size_t test_index)
{
    if (test_index < poc_tests_test_count()) {
        return tests[test_index].name;
    }
    
    return NULL;
}

size_t poc_tests_execute(int* results, size_t size)
{
    size_t how_many_tests_to_run;
    size_t test_counter;
    
    if (NULL == results){
        return 0;
    }
    
    
    how_many_tests_to_run = (size > poc_tests_test_count()) 
        ? poc_tests_test_count() : size;
    
    for (test_counter=0; test_counter<how_many_tests_to_run; ++test_counter) {
        results[test_counter] = tests[test_counter].function();
    }
    
    return test_counter;    
}

int poc_tests_print_results(FILE* outstream, int* results, size_t size)
{
    size_t number_of_tests;
    size_t test_counter;
    size_t failure_counter;
    
    
    if (NULL == outstream) {
        return EINVAL;
    }
    
    if (NULL == results) {
        return EINVAL;
    }
    
    fprintf(outstream, "POC unit test results");
    fprintf(outstream, "\n");
    
    
    number_of_tests = (size > poc_tests_test_count())
        ? poc_tests_test_count() : size;
    
    failure_counter = 0;
    for (test_counter = 0; test_counter < number_of_tests; ++test_counter) {
        if (0 == results[test_counter]) {
            ++failure_counter;
        }
    }
    
    fprintf(outstream, "  %ld unit tests executed, %ld failures detected", 
            number_of_tests,
            failure_counter);
    
    fprintf(outstream, "\n");
    
    if (0 < failure_counter) {
        fprintf(outstream, "  Failed unit tests:");
        fprintf(outstream, "\n");
        
        for (test_counter = 0; test_counter < number_of_tests; ++test_counter) {
            if (0 == results[test_counter]) {
                fprintf(outstream, "    %s failed", tests[test_counter].name);
                fprintf(outstream, "\n");
            }
        }
        
        fprintf(outstream, "\n");
    }
    
    return POC_TESTS_SUCCESS;
}



#include "poc_tests.h"


#include <poc/poc_primary_types.h>


#define CHECK_SIZE(Type, ExpectedSize) (sizeof(Type) * CHAR_BIT == ExpectedSize)
#define CHECK_SIGNED(Type, Result) { Type a = (Type)1 << (sizeof(Type) * CHAR_BIT - 1); Result = (a < (a - 1)); }
#define CHECK_UNSIGNED(Type, Result) { Type a = (Type)1 << (sizeof(Type) * CHAR_BIT - 1); Result = (a > (a - 1)); }


/* @todo TODO: Use function pointer typedef? @c typedef int (*test_func_t)(void);
 */
typedef int (test_func_t)(void);

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








#define TEST_COUNT 2

char const* test_names[TEST_COUNT] = {
    "poc_byte_size_8_test",
    "poc_byte_is_unsigned_test"
};

test_func_t* test_functions[TEST_COUNT] = {
    &poc_byte_size_8_test,
    &poc_byte_is_unsigned_test
};







size_t poc_tests_test_count(void)
{
    return TEST_COUNT;
}


char const* poc_tests_name_of_test(size_t test_index)
{
    if (test_index < TEST_COUNT) {
        return test_names[test_index];
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
    
    
    how_many_tests_to_run = (size > TEST_COUNT) ? TEST_COUNT : size;
    
    for (test_counter = 0; test_counter < how_many_tests_to_run; ++test_counter) {
        results[test_counter] = (test_functions[test_counter])();
    }
    
    return test_counter;    
}

int poc_tests_print_results(FILE* outstream, int* results, size_t size)
{
    return POC_TESTS_ERROR;
}


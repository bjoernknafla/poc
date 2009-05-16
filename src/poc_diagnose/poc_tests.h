


#ifndef POC_HEADER_GUARD_poc_tests_H
#define POC_HEADER_GUARD_poc_tests_H

/* Include CHAR_BIT */
#include <limits.h>

/* Include size_t */
#include <stddef.h>

/* Include FILE */
#include <stdio.h>


#if defined(__cplusplus)
extern "C" {
#endif


#define POC_TESTS_SUCCESS 0
#define POC_TESTS_ERROR -1

/**
 * Returns the number of tests internally defined.
 */
size_t poc_tests_test_count(void);

/**
 * Returns the name of the test associated with index @c index as a null-
 * terminated character string, or @c NULL if no test is associated with the
 * index.
 */
char const* poc_tests_name_of_test(size_t test_index);

/**
 * Runs @c size internal tests or at max all internal tests and returns the
 * number of tests executed.
 */
size_t poc_tests_execute(int* results, size_t size);

/**
 * Prints the results of @c size tests or at max all internal test resuls and
 * returns if an error occured.
 *
 * @todo TODO: Specify error return values.
 */
int poc_tests_print_results(FILE* outstream, int* results, size_t size);



#if defined(__cplusplus)
}
#endif
    
    
#endif /* POC_HEADER_GUARD_poc_tests_H */

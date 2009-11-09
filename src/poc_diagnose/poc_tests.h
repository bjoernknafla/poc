
/**
 * @file
 *
 * Collection of tests checking POC type definitions to have the right bit size
 * signdness and checks other functionality provided by POC, too.
 *
 * @attention None of the test functions is thread-safe as they access a static
 *            variable of the test module.
 */

#ifndef POC_HEADER_GUARD_poc_tests_H
#define POC_HEADER_GUARD_poc_tests_H


/* Include size_t */
#include <stddef.h>

/* Include FILE */
#include <stdio.h>

/* Include EINVAL */
#include <errno.h>



#if defined(__cplusplus)
extern "C" {
#endif


#define POC_TESTS_SUCCESS 0

    
/**
 * Runs all POC unit tests and prints the test summary.
 */
void poc_tests_print_all(FILE* outstream);

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
 * Prints the results of @c size tests or at max all internal test results and
 * returns @c POC_TESTS_SUCCESS. If one of the parameters is invalid @c EINVAL
 * is returned.
 */
int poc_tests_print_results(FILE* outstream, int* results, size_t size);



#if defined(__cplusplus)
}
#endif
    
    
#endif /* POC_HEADER_GUARD_poc_tests_H */

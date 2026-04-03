#include "test_framework.h"

// Sorting
void run_selection_sort_tests(void);
void run_insertion_sort_tests(void);
void run_merge_sort_tests(void);

// Searching
void run_binary_search_tests(void);

int tests_run = 0;
int tests_failed = 0;

int main(void) {
    run_selection_sort_tests();
    run_insertion_sort_tests();
    run_merge_sort_tests();
    run_binary_search_tests();

    TEST_SUMMARY();
    return 0;
}
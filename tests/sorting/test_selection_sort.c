#include "../test_framework.h"
#include "sorting/sorting.h"
#include "utils/array_utils.h"

void test_selection_sort_single_element(void) {
    int a[1] = {1};
    selection_sort(a, 1);
    ASSERT_TRUE(is_sorted_asc(a, 1));
}

void test_selection_sort_sorted(void) {
    int a[4] = {1, 2, 3, 4};
    selection_sort(a, 4);
    ASSERT_TRUE(is_sorted_asc(a, 4));
}

void test_selection_sort_reversed(void) {
    int a[5] = {5, 4, 3, 2, 1};
    selection_sort(a, 5);
    ASSERT_TRUE(is_sorted_asc(a, 5));
}

void test_selection_sort_with_negatives(void) {
    int a[10] = {0, -2, 17, 7, 2, 19, 5, -6, 1, 1};
    selection_sort(a, 10);
    ASSERT_TRUE(is_sorted_asc(a, 10));
}

void run_selection_sort_tests(void) {
    RUN_TEST(test_selection_sort_single_element);
    RUN_TEST(test_selection_sort_sorted);
    RUN_TEST(test_selection_sort_reversed);
    RUN_TEST(test_selection_sort_with_negatives);
}
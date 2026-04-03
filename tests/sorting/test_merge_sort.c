#include "../test_framework.h"
#include "sorting/sorting.h"
#include "utils/array_utils.h"

void test_merge_single_element(void) {
    int a[1] = {1};
    merge(a, 0, 0, 0);
    ASSERT_TRUE(is_sorted_asc(a, 1));
}

void test_merge_two_elements(void) {
    int a[2] = {3, 1};
    merge(a, 0, 0, 1);
    ASSERT_TRUE(is_sorted_asc(a, 2));
}

void test_merge_short_left_subarray(void) {
    int a[8] = {1, 2, 4, 0, 3, 7, 11, 13};
    merge(a, 0, 2, 7);
    ASSERT_TRUE(is_sorted_asc(a, 8));
}

void test_merge_short_right_subarray(void) {
    int a[8] = {0, 3, 7, 11, 13, 1, 2, 4};
    merge(a, 0, 4, 7);
    ASSERT_TRUE(is_sorted_asc(a, 8));
}

void test_merge_strict_subarray(void) {
    int a[16] = {
        0,1,2,3,
        8,9,10,11,
        4,5,6,7,
        12,13,14,15
    };
    merge(a, 4, 7, 11);
    ASSERT_TRUE(is_sorted_asc(a, 16));
}

void test_merge_sort_single_element(void) {
    int a[1] = {1};
    merge_sort(a, 1);
    ASSERT_TRUE(is_sorted_asc(a, 1));
}

void test_merge_sort_sorted(void) {
    int a[16] = {
        0, 3, 4, 17, 19, 25, 32, 33,
        57, 59, 61, 66, 99, 101, 167, 209,
    };
    merge_sort(a, 16);
    ASSERT_TRUE(is_sorted_asc(a, 16));
}

void test_merge_sort_reverse_order(void) {
    int a[5] = {5, 4, 3, 2, 1};
    merge_sort(a, 5);
    ASSERT_TRUE(is_sorted_asc(a, 5));
}

void test_merge_sort_larger_array(void) {
    int a[32] = {
        -5, 7, 0, 2, -17, 7, 3, 0,
        16, 105, 99, -64, 7, -13, 14, 9,
        1, 1, 306, -25, 4, 73, 77, 219,
        51, 44, -5, 5, 67, 32, 0, 11,
    };
    merge_sort(a, 32);
    ASSERT_TRUE(is_sorted_asc(a, 32));
}

void run_merge_sort_tests(void) {
    RUN_TEST(test_merge_single_element);
    RUN_TEST(test_merge_two_elements);
    RUN_TEST(test_merge_short_left_subarray);
    RUN_TEST(test_merge_short_right_subarray);
    RUN_TEST(test_merge_strict_subarray);

    RUN_TEST(test_merge_sort_single_element);
    RUN_TEST(test_merge_sort_sorted);
    RUN_TEST(test_merge_sort_reverse_order);
    RUN_TEST(test_merge_sort_larger_array);
}
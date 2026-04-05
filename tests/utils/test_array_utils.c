#include <stdio.h>
#include "../test_framework.h"
#include "utils/array_utils.h"

bool array_equals(int a[], int b[], int len) {
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }

    return 1;
}

void test_swap_same_index_single_element(void) {
    int a[1] = {2};
    int b[1] = {2};
    swap(a, 0, 0);

    ASSERT_TRUE(array_equals(a, b, 1));
}

void test_swap_same_index(void) {
    int a[9] = {0, 7, -1, 5, 3, 4, -19, 9, 12};
    int b[9] = {0, 7, -1, 5, 3, 4, -19, 9, 12};
    swap(a, 5, 5);

    ASSERT_TRUE(array_equals(a, b, 9));
}

void test_swap_interior_values(void) {
    int a[9] = {0, 7, -1, 5, 3, 4, -19, 9, 12};
    int b[9] = {0, 7, 9, 5, 3, 4, -19, -1, 12};
    swap(a, 2, 7);

    ASSERT_TRUE(array_equals(a, b, 9));
}

void test_swap_boundary_values(void) {
    int a[12] = {0, 7, -1, 5, 3, 4, -19, 9, 12, 6, 1, -3};
    int b[12] = {-3, 7, -1, 5, 3, 4, -19, 9, 12, 6, 1, 0};
    swap(a, 0, 11);

    ASSERT_TRUE(array_equals(a, b, 12));
}

void run_array_utils_tests(void) {
    RUN_TEST(test_swap_same_index_single_element);
    RUN_TEST(test_swap_same_index);
    RUN_TEST(test_swap_interior_values);
    RUN_TEST(test_swap_boundary_values);
}
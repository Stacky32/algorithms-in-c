#include "../test_framework.h"
#include "sorting/sorting.h"
#include "utils/array_utils.h"

void test_selection_sort(void) {
    int a1[4] = {1, 2, 3, 4};
    selection_sort(a1, 4);
    ASSERT_TRUE(is_sorted_asc(a1, 4));

    int a2[4] = {1, 3, 2, 4};
    selection_sort(a2, 4);
    ASSERT_TRUE(is_sorted_asc(a2, 4));

    int a3[5] = {5, 4, 3, 2, 1};
    selection_sort(a3, 5);
    ASSERT_TRUE(is_sorted_asc(a3, 5));

    int a4[10] = {0, -2, 17, 7, 2, 19, 5, -6, 1, 1};
    selection_sort(a4, 10);
    ASSERT_TRUE(is_sorted_asc(a4, 10));
}

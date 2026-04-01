#include "test_framework.h"

void test_selection_sort(void);
void test_binary_search(void);

int tests_run = 0;
int tests_failed = 0;

int main(void) {
    RUN_TEST(test_selection_sort);
    RUN_TEST(test_binary_search);

    TEST_SUMMARY();
    return 0;
}
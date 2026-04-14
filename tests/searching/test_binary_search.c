#include "../test_framework.h"
#include "searching/searching.h"

void test_binary_search(void) {
    int a[64] = {2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,  47,  53,
                 59,  61,  67,  71,  73,  79,  83,  89,  97,  101, 103, 107, 109, 113, 127, 131,
                 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223,
                 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311};

    struct testcase {
        int len;
        int x;
        int expected;
    };

    struct testcase cases[16] = {
        {.len = 1, .x = 4, .expected = -1},      {.len = 1, .x = a[0], .expected = 0},
        {.len = 2, .x = 4, .expected = -1},      {.len = 2, .x = a[0], .expected = 0},
        {.len = 2, .x = a[1], .expected = 1},    {.len = 5, .x = a[3], .expected = 3},
        {.len = 5, .x = 18, .expected = -1},     {.len = 8, .x = a[6], .expected = 6},
        {.len = 17, .x = 999, .expected = -1},   {.len = 17, .x = a[15], .expected = 15},
        {.len = 21, .x = a[9], .expected = 9},   {.len = 21, .x = a[11], .expected = 11},
        {.len = 50, .x = a[42], .expected = 42}, {.len = 64, .x = -5, .expected = -1},
        {.len = 64, .x = a[63], .expected = 63}, {.len = 64, .x = a[0], .expected = 0},
    };

    int numCases = sizeof(cases) / sizeof(struct testcase);

    for (int i = 0; i < numCases; i++) {
        int actual = binary_search(a, cases[i].len, cases[i].x);
        ASSERT_TRUE(actual == cases[i].expected);
    }
}

void run_binary_search_tests(void) {
    RUN_TEST(test_binary_search);
}
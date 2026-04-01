#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <stdio.h>
#include <stdlib.h>

extern int tests_run;
extern int tests_failed;

#define ASSERT_TRUE(condition) \
    do { \
        tests_run++; \
        if (!(condition)) { \
            tests_failed++; \
            printf("❌ FAIL: %s:%d: %s\n", __FILE__, __LINE__, #condition); \
        } else { \
            printf("✅ PASS: %s\n", #condition); \
        } \
    } while (0)

#define RUN_TEST(test_func) \
    do { \
        printf("\nRunning %s...\n", #test_func); \
        test_func(); \
    } while (0)

#define TEST_SUMMARY() \
    do { \
        printf("\n---\nTests run: %d\nFailures: %d\n", tests_run, tests_failed); \
        if (tests_failed == 0) { \
            printf("🎉 ALL TESTS PASSED\n"); \
        } else { \
            printf("⚠️ SOME TESTS FAILED\n"); \
        } \
    } while (0)

#endif
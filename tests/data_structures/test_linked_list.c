#include "../test_framework.h"
#include "data_structures/linked_list.h"

static bool int_cmp_node(struct linked_list_node *node, int value) {
    return *(const int*)node->value == value;
}

void test_linked_list_init_list(void) {
    struct linked_list_list list = {};
    linked_list_init_list(&list, NULL, NULL);
    
    ASSERT_TRUE(list.head == NULL);
    ASSERT_TRUE(list.tail == NULL);
    ASSERT_TRUE(list.count == 0);

    linked_list_free_list(&list);
}

void test_linked_list_delete_head_empty(void) {
    struct linked_list_list list = {};
    linked_list_init_list(&list, NULL, NULL);

    bool res = linked_list_delete_head(&list);
    
    ASSERT_TRUE(!res);
    ASSERT_TRUE(list.count == 0);
    ASSERT_TRUE(list.head == NULL);

    linked_list_free_list(&list);
}

void test_linked_list_delete_head_single_node(void) {
    struct linked_list_list list = {};
    linked_list_init_list(&list, NULL, NULL);
    linked_list_append(&list, &(int){1}, sizeof(int));

    bool res = linked_list_delete_head(&list);
    
    ASSERT_TRUE(res);
    ASSERT_TRUE(list.count == 0);
    ASSERT_TRUE(list.head == NULL);

    linked_list_free_list(&list);
}

void test_linked_list_delete_head(void) {
    struct linked_list_list list = {};
    linked_list_init_list(&list, NULL, NULL);
    
    // Populate with 0 -> 1 -> 2
    int og_len = 3;
    for (int i = 0; i < og_len; i++) {
        linked_list_append(&list, &(int){i}, sizeof(int));
    }

    bool res = linked_list_delete_head(&list);

    ASSERT_TRUE(res);
    ASSERT_TRUE(list.count == og_len - 1);
    ASSERT_TRUE(int_cmp_node(list.head, 1));

    linked_list_free_list(&list);
}

void test_linked_list_delete_tail_empty(void) {
    struct linked_list_list list = {};
    linked_list_init_list(&list, NULL, NULL);

    bool res = linked_list_delete_tail(&list);

    ASSERT_TRUE(!res);
    ASSERT_TRUE(list.count == 0);
    ASSERT_TRUE(list.tail == NULL);

    linked_list_free_list(&list);
}

void test_linked_list_delete_tail_single_node(void) {
    struct linked_list_list list = {};
    linked_list_init_list(&list, NULL, NULL);
    linked_list_append(&list, &(int){1}, sizeof(int));

    bool res = linked_list_delete_tail(&list);

    ASSERT_TRUE(res);
    ASSERT_TRUE(list.count == 0);
    ASSERT_TRUE(list.tail == NULL);

    linked_list_free_list(&list);
}

void test_linked_list_delete_tail_two_nodes(void) {
    struct linked_list_list list = {};
    linked_list_init_list(&list, NULL, NULL);

    // Populate with 0 -> 1
    int og_len = 2;
    for (int i = 0; i < og_len; i++) {
        linked_list_append(&list, &(int){i}, sizeof(int));
    }

    bool res = linked_list_delete_tail(&list);

    ASSERT_TRUE(res);
    ASSERT_TRUE(list.count == og_len - 1);
    ASSERT_TRUE(int_cmp_node(list.tail, 0));
    ASSERT_TRUE(list.tail->next == NULL);

    linked_list_free_list(&list);
}

void test_linked_list_delete_tail_three_nodes(void) {
    struct linked_list_list list = {};
    linked_list_init_list(&list, NULL, NULL);

    // Populate with 0 -> 1 -> 2
    int og_len = 3;
    for (int i = 0; i < og_len; i++) {
        linked_list_append(&list, &(int){i}, sizeof(int));
    }

    bool res = linked_list_delete_tail(&list);

    ASSERT_TRUE(res);
    ASSERT_TRUE(list.count == og_len - 1);
    ASSERT_TRUE(int_cmp_node(list.tail, 1));
    ASSERT_TRUE(list.tail->next == NULL);

    linked_list_free_list(&list);
}

void test_linked_list_prepend(void) {
    struct linked_list_list list = {};
    linked_list_init_list(&list, NULL, NULL);

    int a[2] = {3, 5};
    linked_list_prepend(&list, &a[0], sizeof(int));
    linked_list_prepend(&list, &a[1], sizeof(int));

    ASSERT_TRUE(list.count == 2);
    ASSERT_TRUE(int_cmp_node(list.head, a[1]));
    ASSERT_TRUE(int_cmp_node(list.head->next, a[0]));

    linked_list_free_list(&list);
}

void test_linked_list_free_list_null(void) {
    linked_list_free_list(NULL);
    ASSERT_TRUE(true); // No genuine assertions to be made, but no crash.
}

void test_linked_list_free_list_empty(void) {
    struct linked_list_list list = {};
    linked_list_init_list(&list, NULL, NULL);

    linked_list_free_list(&list);

    ASSERT_TRUE(list.count == 0);
    ASSERT_TRUE(list.head == NULL);
    ASSERT_TRUE(list.tail == NULL);
}

void test_linked_list_free_list(void) {
    struct linked_list_list list = {};
    linked_list_init_list(&list, NULL, NULL);

    int a[3] = {3, 5, 8};
    linked_list_prepend(&list, &a[0], sizeof(int));
    linked_list_prepend(&list, &a[1], sizeof(int));
    linked_list_prepend(&list, &a[2], sizeof(int));
    
    linked_list_free_list(&list);

    ASSERT_TRUE(list.count == 0);
    ASSERT_TRUE(list.head == NULL);
    ASSERT_TRUE(list.tail == NULL);
}

void test_linked_list_append(void) {
    struct linked_list_list list = {};
    linked_list_init_list(&list, NULL, NULL);

    int a[2] = {3, 5};
    linked_list_append(&list, &a[0], sizeof(int));
    linked_list_append(&list, &a[1], sizeof(int));

    ASSERT_TRUE(list.count == 2);
    ASSERT_TRUE(int_cmp_node(list.head, a[0]));
    ASSERT_TRUE(int_cmp_node(list.head->next, a[1]));

    linked_list_free_list(&list);
}

void test_linked_list_insert_empty(void) {
    struct linked_list_list list = {};
    linked_list_init_list(&list, NULL, NULL);

    int x = 7;
    linked_list_insert(&list, &x, 0, sizeof(int));
    
    ASSERT_TRUE(list.count == 1);
    ASSERT_TRUE(int_cmp_node(list.head, x));
    ASSERT_TRUE(int_cmp_node(list.tail, x));

    linked_list_free_list(&list);
}

void test_linked_list_insert_at_head(void) {
    struct linked_list_list list = {};
    linked_list_init_list(&list, NULL, NULL);

    linked_list_append(&list, &(int){1}, sizeof(int));
    linked_list_append(&list, &(int){2}, sizeof(int));

    int x = 7;
    linked_list_insert(&list, &x, 0, sizeof(int));
    
    ASSERT_TRUE(list.count == 3);
    ASSERT_TRUE(int_cmp_node(list.head, x));

    linked_list_free_list(&list);
}

void test_linked_list_insert_at_tail(void) {
    struct linked_list_list list = {};
    linked_list_init_list(&list, NULL, NULL);

    linked_list_append(&list, &(int){1}, sizeof(int));
    linked_list_append(&list, &(int){2}, sizeof(int));

    int x = 7;
    linked_list_insert(&list, &x, 2, sizeof(int));
    
    ASSERT_TRUE(list.count == 3);
    ASSERT_TRUE(int_cmp_node(list.tail, x));

    linked_list_free_list(&list);
}

void test_linked_list_insert(void) {
    struct linked_list_list list = {};
    linked_list_init_list(&list, NULL, NULL);

    int og_len = 5;
    for (int i = 0; i < og_len; i++) {
        linked_list_append(&list, &i, sizeof(int));
    }

    int x = 11;
    linked_list_insert(&list, &x, 2, sizeof(int));

    ASSERT_TRUE(list.count == og_len + 1);
    ASSERT_TRUE(int_cmp_node(list.head->next->next, x));

    linked_list_free_list(&list);
}

void run_linked_list_tests(void) {
    RUN_TEST(test_linked_list_init_list);

    RUN_TEST(test_linked_list_delete_head_empty);
    RUN_TEST(test_linked_list_delete_head_single_node);
    RUN_TEST(test_linked_list_delete_head);

    RUN_TEST(test_linked_list_delete_tail_empty);
    RUN_TEST(test_linked_list_delete_tail_single_node);
    RUN_TEST(test_linked_list_delete_tail_two_nodes);
    RUN_TEST(test_linked_list_delete_tail_three_nodes);

    RUN_TEST(test_linked_list_prepend);

    RUN_TEST(test_linked_list_free_list_null);
    RUN_TEST(test_linked_list_free_list_empty);
    RUN_TEST(test_linked_list_free_list);

    RUN_TEST(test_linked_list_append);

    RUN_TEST(test_linked_list_insert_empty);
    RUN_TEST(test_linked_list_insert_at_head);
    RUN_TEST(test_linked_list_insert_at_tail);
    RUN_TEST(test_linked_list_insert);
}
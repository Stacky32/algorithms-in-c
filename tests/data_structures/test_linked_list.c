#include "../test_framework.h"
#include "data_structures/linked_list.h"

static bool int_cmp_node(struct linked_list_node *node, int value) {
    return node != NULL && *(const int *)node->value == value;
}

static bool int_cmp(const void *a, const void *b) {
    return *(const int *)a == *(const int *)b;
}

// Initialise a list with range 0 to len - 1
static void init_range_list(struct linked_list_list *list, int len) {
    linked_list_init_list(list, int_cmp, NULL);

    for (int i = 0; i < len; i++) {
        linked_list_append(list, &i, sizeof(int));
    }
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
    init_range_list(&list, 0);

    bool res = linked_list_delete_head(&list);

    ASSERT_TRUE(!res);
    ASSERT_TRUE(list.count == 0);
    ASSERT_TRUE(list.head == NULL);

    linked_list_free_list(&list);
}

void test_linked_list_delete_head_single_node(void) {
    struct linked_list_list list = {};
    init_range_list(&list, 1);

    bool res = linked_list_delete_head(&list);

    ASSERT_TRUE(res);
    ASSERT_TRUE(list.count == 0);
    ASSERT_TRUE(list.head == NULL);

    linked_list_free_list(&list);
}

void test_linked_list_delete_head(void) {
    int og_len = 3;
    struct linked_list_list list = {};
    init_range_list(&list, og_len);

    bool res = linked_list_delete_head(&list);

    ASSERT_TRUE(res);
    ASSERT_TRUE(list.count == og_len - 1);
    ASSERT_TRUE(int_cmp_node(list.head, 1));

    linked_list_free_list(&list);
}

void test_linked_list_delete_tail_empty(void) {
    struct linked_list_list list = {};
    init_range_list(&list, 0);

    bool res = linked_list_delete_tail(&list);

    ASSERT_TRUE(!res);
    ASSERT_TRUE(list.count == 0);
    ASSERT_TRUE(list.tail == NULL);

    linked_list_free_list(&list);
}

void test_linked_list_delete_tail_single_node(void) {
    struct linked_list_list list = {};
    init_range_list(&list, 1);

    bool res = linked_list_delete_tail(&list);

    ASSERT_TRUE(res);
    ASSERT_TRUE(list.count == 0);
    ASSERT_TRUE(list.tail == NULL);

    linked_list_free_list(&list);
}

void test_linked_list_delete_tail_two_nodes(void) {
    int og_len = 2;
    struct linked_list_list list = {};
    init_range_list(&list, og_len);

    bool res = linked_list_delete_tail(&list);

    ASSERT_TRUE(res);
    ASSERT_TRUE(list.count == og_len - 1);
    ASSERT_TRUE(int_cmp_node(list.tail, 0));
    ASSERT_TRUE(list.tail->next == NULL);

    linked_list_free_list(&list);
}

void test_linked_list_delete_tail_three_nodes(void) {
    int og_len = 3;
    struct linked_list_list list = {};
    init_range_list(&list, og_len);

    bool res = linked_list_delete_tail(&list);

    ASSERT_TRUE(res);
    ASSERT_TRUE(list.count == og_len - 1);
    ASSERT_TRUE(int_cmp_node(list.tail, 1));
    ASSERT_TRUE(list.tail->next == NULL);

    linked_list_free_list(&list);
}

void test_linked_list_delete_value_empty(void) {
    struct linked_list_list list = {};
    init_range_list(&list, 0);

    bool res = linked_list_delete_value(&list, &(int){1});

    ASSERT_TRUE(!res);

    linked_list_free_list(&list);
}

void test_linked_list_delete_value_item_not_found(void) {
    int og_len = 3;
    struct linked_list_list list = {};
    init_range_list(&list, og_len);

    bool res = linked_list_delete_value(&list, &(int){17});

    ASSERT_TRUE(!res);
    ASSERT_TRUE(list.count == og_len);

    linked_list_free_list(&list);
}

void test_linked_list_delete_value_at_head(void) {
    int og_len = 3;
    struct linked_list_list list = {};
    init_range_list(&list, og_len);

    bool res = linked_list_delete_value(&list, &(int){0});

    ASSERT_TRUE(res);
    ASSERT_TRUE(list.count == og_len - 1);
    ASSERT_TRUE(int_cmp_node(list.head, 1));

    linked_list_free_list(&list);
}

void test_linked_list_delete_value_at_tail(void) {
    int og_len = 3;
    struct linked_list_list list = {};
    init_range_list(&list, og_len);

    bool res = linked_list_delete_value(&list, &(int){2});

    ASSERT_TRUE(res);
    ASSERT_TRUE(list.count == og_len - 1);
    ASSERT_TRUE(int_cmp_node(list.tail, 1));

    linked_list_free_list(&list);
}

void test_linked_list_delete_value_interior(void) {
    int og_len = 3;
    struct linked_list_list list = {};
    init_range_list(&list, og_len);

    bool res = linked_list_delete_value(&list, &(int){1});

    ASSERT_TRUE(res);
    ASSERT_TRUE(list.count == og_len - 1);

    linked_list_free_list(&list);
}

void test_linked_list_prepend(void) {
    struct linked_list_list list = {};
    init_range_list(&list, 0);

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
    init_range_list(&list, 0);

    linked_list_free_list(&list);

    ASSERT_TRUE(list.count == 0);
    ASSERT_TRUE(list.head == NULL);
    ASSERT_TRUE(list.tail == NULL);
}

void test_linked_list_free_list(void) {
    struct linked_list_list list = {};
    init_range_list(&list, 5);

    linked_list_free_list(&list);

    ASSERT_TRUE(list.count == 0);
    ASSERT_TRUE(list.head == NULL);
    ASSERT_TRUE(list.tail == NULL);
}

void test_linked_list_append(void) {
    struct linked_list_list list = {};
    init_range_list(&list, 0);

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
    init_range_list(&list, 0);

    int x = 7;
    linked_list_insert(&list, &x, 0, sizeof(int));

    ASSERT_TRUE(list.count == 1);
    ASSERT_TRUE(int_cmp_node(list.head, x));
    ASSERT_TRUE(int_cmp_node(list.tail, x));

    linked_list_free_list(&list);
}

void test_linked_list_insert_at_head(void) {
    int og_len = 3;
    struct linked_list_list list = {};
    init_range_list(&list, og_len);

    int x = 7;
    linked_list_insert(&list, &x, 0, sizeof(int));

    ASSERT_TRUE(list.count == og_len + 1);
    ASSERT_TRUE(int_cmp_node(list.head, x));

    linked_list_free_list(&list);
}

void test_linked_list_insert_at_tail(void) {
    int og_len = 7;
    struct linked_list_list list = {};
    init_range_list(&list, og_len);

    int x = 7;
    linked_list_insert(&list, &x, og_len, sizeof(int));

    ASSERT_TRUE(list.count == og_len + 1);
    ASSERT_TRUE(int_cmp_node(list.tail, x));

    linked_list_free_list(&list);
}

void test_linked_list_insert(void) {
    int og_len = 5;
    struct linked_list_list list = {};
    init_range_list(&list, og_len);

    int x = 11;
    linked_list_insert(&list, &x, 2, sizeof(int));

    ASSERT_TRUE(list.count == og_len + 1);
    ASSERT_TRUE(int_cmp_node(list.head->next->next, x));

    linked_list_free_list(&list);
}

void test_linked_list_find_at_empty(void) {
    struct linked_list_list list = {};
    init_range_list(&list, 0);

    struct linked_list_node *res = linked_list_find(&list, &(int){1});

    ASSERT_TRUE(res == NULL);

    linked_list_free_list(&list);
}

void test_linked_list_find_item_not_found(void) {
    struct linked_list_list list = {};
    init_range_list(&list, 5);

    struct linked_list_node *res = linked_list_find(&list, &(int){-1});

    ASSERT_TRUE(res == NULL);

    linked_list_free_list(&list);
}

void test_linked_list_find_at_head(void) {
    struct linked_list_list list = {};
    init_range_list(&list, 5);

    int value = 0;
    struct linked_list_node *res = linked_list_find(&list, &value);

    ASSERT_TRUE(res != NULL);
    ASSERT_TRUE(int_cmp_node(res, value));

    linked_list_free_list(&list);
}

void test_linked_list_find_at_tail(void) {
    int len = 7;
    struct linked_list_list list = {};
    init_range_list(&list, len);

    int value = len - 1;
    struct linked_list_node *res = linked_list_find(&list, &value);

    ASSERT_TRUE(res != NULL);
    ASSERT_TRUE(int_cmp_node(res, value));

    linked_list_free_list(&list);
}

void test_linked_list_find_interior(void) {
    struct linked_list_list list = {};
    init_range_list(&list, 17);

    int value = 14;
    struct linked_list_node *res = linked_list_find(&list, &value);

    ASSERT_TRUE(res != NULL);
    ASSERT_TRUE(int_cmp_node(res, value));

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

    RUN_TEST(test_linked_list_delete_value_empty);
    RUN_TEST(test_linked_list_delete_value_item_not_found);
    RUN_TEST(test_linked_list_delete_value_at_head);
    RUN_TEST(test_linked_list_delete_value_at_tail);
    RUN_TEST(test_linked_list_delete_value_interior);

    RUN_TEST(test_linked_list_prepend);

    RUN_TEST(test_linked_list_free_list_null);
    RUN_TEST(test_linked_list_free_list_empty);
    RUN_TEST(test_linked_list_free_list);

    RUN_TEST(test_linked_list_append);

    RUN_TEST(test_linked_list_insert_empty);
    RUN_TEST(test_linked_list_insert_at_head);
    RUN_TEST(test_linked_list_insert_at_tail);
    RUN_TEST(test_linked_list_insert);

    RUN_TEST(test_linked_list_find_at_empty);
    RUN_TEST(test_linked_list_find_item_not_found);
    RUN_TEST(test_linked_list_find_at_head);
    RUN_TEST(test_linked_list_find_at_tail);
    RUN_TEST(test_linked_list_find_interior);
}
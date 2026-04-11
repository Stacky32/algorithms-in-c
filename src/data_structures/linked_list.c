/* linked_list.c
* Implementation of a generic singly linked list
*/

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "data_structures/linked_list.h"

static struct linked_list_node* linked_list_create_node(void *value, size_t elem_size) {
    // allocate node
    struct linked_list_node *node = malloc(sizeof(struct linked_list_node));
    assert(node != NULL);

    // allocate data
    node->value = malloc(elem_size);
    assert(node->value != NULL);

    // copy value
    memcpy(node->value, value, elem_size);

    // set next to null
    node->next = NULL;

    return node;
}

static void linked_list_free_node(struct linked_list_node *node) {
    if (node == NULL) {
        return; // free(NULL) is a no-op
    }

    free(node->value);
    node->value = NULL;
    node->next = NULL;
    free(node);
}

void linked_list_init_list(
    struct linked_list_list *list,
    bool (*cmp)(const void*, const void*),
    void (*print)(const void*)) {
    
    assert(list != NULL);
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    list->cmp = cmp;
    list->print = print;
}

static bool linked_list_delete_head(struct linked_list_list *list) {
    assert(list != NULL);
    
    if (list->count == 0) {
        return false;
    }

    struct linked_list_node *new_head = list->head->next;
    linked_list_free_node(list->head);
    list->head = new_head;
    list->count--;
    return true;
}

static void linked_list_clear_list(struct linked_list_list *list) {
    assert(list != NULL);

    while (linked_list_delete_head(list)) {
        continue;
    }

    list->head = NULL;
    list->count = 0;
}

void linked_list_free_list(struct linked_list_list *list) {
    if (list == NULL) {
        return; // free(NULL) is a no-op
    }

    linked_list_clear_list(list);
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    list->cmp = NULL;
    list->print = NULL;
}

void linked_list_prepend(
    struct linked_list_list *list,
    void *value,
    size_t elem_size) {

    assert(list != NULL);
    struct linked_list_node *node = linked_list_create_node(value, elem_size);
    
    if (list->count == 0) {
        list->head = node;
        list->tail = node;
    } else {
        node->next = list->head;
        list->head = node;
    }

    list->count++;
}

void linked_list_append(
    struct linked_list_list *list,
    void *value,
    size_t elem_size) {
    
    assert(list != NULL);
    struct linked_list_node *node = linked_list_create_node(value, elem_size);

    if (list->count == 0) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }

    list->count++;
}
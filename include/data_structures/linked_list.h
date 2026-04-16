#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

struct linked_list_node {
    struct linked_list_node *next;
    void *value;
};

struct linked_list_list {
    struct linked_list_node *head;
    struct linked_list_node *tail;
    int count;

    // Comparison and display function pointers
    bool (*cmp)(const void *, const void *);
    void (*print)(const void *);
};

void linked_list_init_list(struct linked_list_list *list, bool (*cmp)(const void *, const void *),
                           void (*print)(const void *));

bool linked_list_delete_head(struct linked_list_list *list);

bool linked_list_delete_tail(struct linked_list_list *list);

bool linked_list_delete_value(struct linked_list_list *list, void *value);

struct linked_list_node *linked_list_find(struct linked_list_list *list, void *value);

void linked_list_free_list(struct linked_list_list *list);

void linked_list_prepend(struct linked_list_list *list, void *value, size_t elem_size);

void linked_list_append(struct linked_list_list *list, void *value, size_t elem_size);

void linked_list_insert(struct linked_list_list *list, void *value, int index, size_t elem_size);

#endif

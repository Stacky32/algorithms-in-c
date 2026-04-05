#include "sorting/sorting.h"
#include "utils/array_utils.h"
#include "assert.h"

int partition(int a[], int p, int r) {
    assert(p >= 0);
    assert(p <= r);

    int q = p;
    for (int j = p; j < r; j++) {
        if (a[j] <= a[r]) {
            swap(a, j, q++);
        }
    }

    swap(a, r, q);
    return q;
}

void quick_sort_internal(int a[], int p, int r) {
    if (r <= p) {
        return;
    }

    int q = partition(a, p, r);
    quick_sort_internal(a, p, q-1);
    quick_sort_internal(a, q+1, r);
}

void quick_sort(int a[], int len) {
    quick_sort_internal(a, 0, len - 1);
}
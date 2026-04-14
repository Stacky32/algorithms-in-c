#include "sorting/sorting.h"

// Inserts the value in the sorted sub-array ending at rightIdx,
// such that the subarray ending at rightIdx+1 remain sorted.
// Bounds checking is not performed, so rightIdx must satisfy
// rightIdx + 1 < len(a).
void insert_in_order(int a[], int rightIdx, int x) {
    while (rightIdx >= 0 && a[rightIdx] > x) {
        a[rightIdx + 1] = a[rightIdx];
        rightIdx--;
    }

    a[rightIdx + 1] = x;
}

void insertion_sort(int a[], int len) {
    for (int i = 0; i < len - 1; i++) {
        insert_in_order(a, i, a[i + 1]);
    }
}

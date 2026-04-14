#include "sorting/sorting.h"

#include <stdlib.h>

void merge(int a[], int left, int mid, int right) {
    // Create temporary sub arrays for indices [left..mid] and [mid+1..right]
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *a1 = malloc(n1 * sizeof(int));
    int *a2 = malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) {
        a1[i] = a[left + i];
    }

    for (j = 0; j < n2; j++) {
        a2[j] = a[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    // Repeatedly compare the elements in a1 and a2, inserting the smallest into a.
    while (i < n1 && j < n2) {
        if (a1[i] < a2[j]) {
            a[k++] = a1[i++];
        } else {
            a[k++] = a2[j++];
        }
    }

    // Add remaining elements from a1 or a2 into a
    while (i < n1) {
        a[k++] = a1[i++];
    }

    while (j < n2) {
        a[k++] = a2[j++];
    }

    free(a2);
    free(a1);
}

// Implements the recursive merge sort algorithm to sort the subarray
// with indices [left..right] in ascending order.
void merge_sort_internal(int a[], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;
    merge_sort_internal(a, left, mid);
    merge_sort_internal(a, mid + 1, right);
    merge(a, left, mid, right);
}

void merge_sort(int a[], int len) {
    merge_sort_internal(a, 0, len - 1);
}
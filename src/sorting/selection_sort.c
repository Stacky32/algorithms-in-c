#include <stdio.h>
#include "sorting/sorting.h"

void swap(int a[], int i, int j) {
    a[i] = a[i] ^ a[j];
    a[j] = a[i] ^ a[j];
    a[i] = a[i] ^ a[j];
}

int index_of_minimum(int a[], int len, int startIdx) {
    if (startIdx >= len) {
        return -1;
    }

    int minIndex = startIdx;
    int minValue = a[startIdx];

    for (int i = startIdx; i < len; i++) {
        if (a[i] < minValue) {
            minIndex = i;
            minValue = a[i];
        }
    }

    return minIndex;
}

void selection_sort(int a[], int len) {
    for (int i = 0; i < len - 1; i++) {
        int minIndex = index_of_minimum(a, len, i);
        if (minIndex > i) {
            swap(a, i, minIndex);
        }
    }
}

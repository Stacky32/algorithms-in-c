#include "sorting/sorting.h"
#include "utils/array_utils.h"

// Finds the index of the first occurence of the minimum value
// in an array of integers, starting from the start index.
// If the start index is out of range, -1 is returned.
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

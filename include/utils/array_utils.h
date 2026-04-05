#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

// Indicates whether an array of integers is in ascending order.
// TODO: Consider moving into tests module.
bool is_sorted_asc(int a[], int len);

// Swaps the elements and indices i and j in an array of integers.
// No bounds checking is performed on i and j, so it is crucial
// to check these indices are within range.
void swap(int a[], int i, int j);

#endif
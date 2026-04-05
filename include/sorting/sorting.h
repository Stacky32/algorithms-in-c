#ifndef SORTING_H
#define SORTING_H

// Performs the selection sort algorithm to sort an array of integers
// in-place in ascending order.
void selection_sort(int a[], int len);

// Performs the insertion sort algorithm to sort an array of integers
// in-place in ascending order.
void insertion_sort(int a[], int len);

// Sorts an array of integers in ascending order by merging the sorted subarrays
// with indices [left..mid] and [mid+1..right].
void merge(int a[], int left, int mid, int right);

// Performs the merge sort algorithm to sort an array of integers
// in ascending order.
void merge_sort(int a[], int len);

// Performs the quick sort algorithm to sort an array of integers
// in ascending order, using the last element of a subarray as the pivot.
void quick_sort(int a[], int len);

#endif
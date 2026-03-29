#include <stdio.h>

void selectionSort(int a[], int len);
void checkResult(int a[], int len);

int main(void) {
    int a1[4] = {1, 2, 3, 4};
    selectionSort(a1, 4);
    checkResult(a1, 4);

    int a2[4] = {1, 3, 2, 4};
    selectionSort(a2, 4);
    checkResult(a2, 4);

    int a3[5] = {5, 4, 3, 2, 1};
    selectionSort(a3, 5);
    checkResult(a3, 5);
    
    int a4[10] = {0, -2, 17, 7, 2, 19, 5, -6, 1, 1};
    selectionSort(a4, 10);
    checkResult(a4, 10);
}

void swap(int a[], int i, int j) {
    a[i] = a[i] ^ a[j];
    a[j] = a[i] ^ a[j];
    a[i] = a[i] ^ a[j];
}

int indexOfMinimum(int a[], int len, int startIdx) {
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

void selectionSort(int a[], int len) {
    for (int i = 0; i < len - 1; i++) {
        int minIndex = indexOfMinimum(a, len, i);
        if (minIndex > i) {
            swap(a, i, minIndex);
        }
    }
}

bool isSorted(int a[], int len) {
    for (int i = 1; i < len; i++) {
        if (a[i-1] > a[i]) {
            return 0;
        }
    }

    return 1;
}

void displayArray(int a[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void checkResult(int a[], int len) {
    if (isSorted(a, len)) {
        printf("PASS\n");
    } else {
        printf("FAIL - array is not sorted:\n");
        displayArray(a, len);
        printf("\n");
    }
}

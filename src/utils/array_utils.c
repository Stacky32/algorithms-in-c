#include "utils/array_utils.h"

bool is_sorted_asc(int a[], int len) {
    for (int i = 1; i < len; i++) {
        if (a[i-1] > a[i]) {
            return 0;
        }
    }

    return 1;
}
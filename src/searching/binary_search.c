#include "searching/searching.h"

int binary_search(int arr[], int len, int tg) {
    int min = 0;
    int max = len - 1;
    int guess = 0;

    while (max >= min) {
        guess = (min + max) / 2;

        int v = arr[guess];
        if (v == tg) {
            return guess;
        }

        if (v < tg) {
            min = guess + 1;
        } else {
            max = guess - 1;
        }
    }

    return -1;
}
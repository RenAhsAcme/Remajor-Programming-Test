//
// Created by renahsacme on 2026/4/10.
//
#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *number, int l, int r) {
    if (l >= r) return;
    int i = l, j = r, pivot = number[(l + r) / 2];
    while (i <= j) {
        while (number[i] < pivot) i++;
        while (number[j] > pivot) j--;
        if (i <= j) {
            int tmp = number[i];
            number[i] = number[j], number[j] = tmp, i++, j--;
        }
    }
    quick_sort(number, l, j), quick_sort(number, i, r);
}

int main() {
    static char buffer[100000000];
    char *next = NULL, *endptr = NULL;
    int n = 0, k = 0;
    if (fgets(buffer, sizeof(buffer), stdin)) {
        next = buffer, n = (int) strtol(next, &endptr, 10);
        next = endptr, k = (int) strtol(next, &endptr, 10);
    }
    int *number = calloc(n, sizeof(int));
    if (fgets(buffer, sizeof(buffer), stdin)) {
        next = buffer;
        for (int i = 0; i < n; i++) number[i] = (int) strtol(next, &endptr, 10), next = endptr;
    }
    quick_sort(number, 0, n - 1), printf("%d", number[k]), free(number);
    return 0;
}

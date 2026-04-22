//
// Created by renahsacme on 2026/4/10.
//
#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *a, int l, int r) {
    if (l >= r) return;
    int i = l, j = r, pivot = a[(l + r) / 2];
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            int tmp = a[i];
            a[i] = a[j], a[j] = tmp, i++, j--;
        }
    }
    quick_sort(a, l, j), quick_sort(a, i, r);
}

int main() {
    char buffer[100000] = {}, *next = NULL, *endptr = NULL;
    int count = 0;
    if (fgets(buffer, sizeof(buffer), stdin)) count = (int) strtol(buffer, NULL, 10);
    int *number = calloc(count, sizeof(int));
    if (fgets(buffer, sizeof(buffer), stdin)) {
        next = buffer;
        for (int i = 0; i < count; i++) {
            number[i] = (int) strtol(next, &endptr, 10);
            if (endptr == next) break;
            next = endptr;
        }
    }
    quick_sort(number, 0, count - 1);
    for (int i = 0; i < count; i++) printf("%d ", number[i]);
    free(number);
    return 0;
}

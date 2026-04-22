//
// Created by renahsacme on 2026/4/10.
//
#include <stdio.h>
#include <stdlib.h>

void quick_sort(int a[], int l, int r) {
    if (l >= r) return;
    int i = l, j = r, pivot = a[(l + r) / 2];
    while (i <= j) {
        while (a[i] > pivot) i++;
        while (a[j] < pivot) j--;
        if (i <= j) {
            int tmp = a[i];
            a[i] = a[j], a[j] = tmp, i++, j--;
        }
    }
    quick_sort(a, l, j), quick_sort(a, i, r);
}

int main() {
    char buffer[1000] = {}, *next = NULL, *endptr = NULL;
    int N = 0, B = 0, actual_height = 0, actual_num = 0;
    if (fgets(buffer, sizeof(buffer), stdin)) {
        next = buffer, N = (int) strtol(next, &endptr, 10);
        next = endptr, B = (int) strtol(next, &endptr, 10);
    }
    int *height = calloc(N, sizeof(int));
    for (int i = 0; i < N; i++)
        if (fgets(buffer, sizeof(buffer), stdin))
            height[i] = (int) strtol(buffer, NULL, 10);
    quick_sort(height, 0, N - 1);
    for (int i = 0; i < N; i++)
        if ((actual_height += height[i]) < B) actual_num++;
        else {
            actual_num++;
            break;
        }
    printf("%d", actual_num), free(height);
    return 0;
}

//
// Created by renahsacme on 2026/4/9.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 记住这里的排序算法代码 - 快速排序 ========================================================================================
void quick_sort(int a[], int l, int r) {
    if (l >= r) return;
    int i = l, j = r, pivot = a[(l + r) / 2];;
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
// =====================================================================================================================

int main() {
    char buffer[50] = {}, *next = NULL, *endptr = NULL;
    int M = 0, count = 0;
    if (fgets(buffer, sizeof(buffer), stdin))
        M = (int) strtol(buffer, NULL, 10);
    int origin_int[M] = {};
    strcpy(buffer, "");
    if (fgets(buffer, sizeof(buffer), stdin)) {
        next = buffer;
        for (int i = 0; i < M; i++)
            origin_int[i] = (int) strtol(next, &endptr, 10), next = endptr;
    }
    quick_sort(origin_int, 0, M - 1);
    for (int i = 0; i < M; i++) {
        if (origin_int[i] == -1)
            continue;
        if (i != M - 1)
            for (int j = i + 1; j < M; j++)
                if (origin_int[i] == origin_int[j])
                    origin_int[j] = -1;
        count++;
    }
    printf("%d\n", count);
    for (int i = 0; i < M; i++)
        if (origin_int[i] != -1)
            printf("%d ", origin_int[i]);
    return 0;
}

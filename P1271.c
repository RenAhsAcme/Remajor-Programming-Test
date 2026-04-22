//
// Created by renahsacme on 2026/4/10.
//
#include <stdio.h>
#include <stdlib.h>

void quick_sort(int a[], int l, int r) {
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
    char buffer[10000] = {}, *next = NULL, *endptr = NULL;
    int m = 0;
    if (fgets(buffer, sizeof(buffer), stdin))
        strtol(buffer, &endptr, 10), m = (int) strtol(endptr, NULL, 10);
    int *m_num = calloc(m, sizeof(int));
    if (fgets(buffer, sizeof(buffer), stdin)) {
        next = buffer;
        for (int i = 0; i < m; i++) m_num[i] = (int) strtol(next, &endptr, 10), next = endptr;
    }
    quick_sort(m_num, 0, m - 1);
    for (int i = 0; i < m; i++) printf("%d ", m_num[i]);
    free(m_num);
    return 0;
}

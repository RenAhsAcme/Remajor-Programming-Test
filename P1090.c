//
// Created by renahsacme on 2026/4/12.
//
#include <stdio.h>
#include <stdlib.h>

void quick_sort(long long *a, int l, int r) {
    if (l >= r) return;
    int i = l, j = r;
    long long pivot = a[(l + r) / 2];
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            long long tmp = a[i];
            a[i] = a[j], a[j] = tmp, i++, j--;
        }
    }
    quick_sort(a, l, j), quick_sort(a, i, r);
}

int main() {
    char *next = NULL, *endptr = NULL;
    static char buffer[2000000000] = {};
    int n = 0;
    long long sum = 0;
    if (fgets(buffer, sizeof(buffer), stdin)) n = (int) strtol(buffer, NULL, 10);
    long long *fruit_num = calloc(n, sizeof(long long));
    if (fgets(buffer, sizeof(buffer), stdin)) {
        next = buffer;
        for (int i = 0; i < n; i++) fruit_num[i] = strtoll(next, &endptr, 10), next = endptr;
    }
    quick_sort(fruit_num, 0, n - 1);
    for (int i = 0; i < n - 1; i++) {
        sum += fruit_num[i] + fruit_num[i + 1], fruit_num[i + 1] = fruit_num[i] + fruit_num[i + 1];
        quick_sort(fruit_num, i + 1, n - 1);
    }
    printf("%lld", sum), free(fruit_num);
    return 0;
}

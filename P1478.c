//
// Created by renahsacme on 2026/4/12.
//
#include <stdio.h>
#include <stdlib.h>

struct apple {
    int x, y;
};

void quick_sort(struct apple a[], int l, int r) {
    if (l >= r) return;
    int i = l, j = r;
    struct apple pivot = a[(l + r) / 2];
    while (i <= j) {
        while (a[i].y < pivot.y) i++;
        while (a[j].y > pivot.y) j--;
        if (i <= j) {
            struct apple tmp = a[i];
            a[i] = a[j], a[j] = tmp, i++, j--;
        }
    }
    quick_sort(a, l, j), quick_sort(a, i, r);
}

int main() {
    char buffer[256] = {}, *next = NULL, *endptr = NULL;
    int n = 0, s = 0, a = 0, b = 0, cnt = 0, sum = 0, j = 0;
    if (fgets(buffer, sizeof(buffer), stdin))
        next = buffer, n = (int) strtol(next, &endptr, 10), next = endptr, s = (int) strtol(next, NULL, 10);
    struct apple *Apple = calloc(n, sizeof(struct apple));
    if (fgets(buffer, sizeof(buffer), stdin))
        next = buffer, a = (int) strtol(next, &endptr, 10), next = endptr, b = (int) strtol(next, NULL, 10);
    for (int i = 0; i < n; i++)
        if (fgets(buffer, sizeof(buffer), stdin)) {
            next = buffer;
            int tmp = (int) strtol(next, &endptr, 10);
            if (tmp <= a + b)
                Apple[cnt].x = tmp, next = endptr, Apple[cnt].y = (int) strtol(next, NULL, 10), cnt++;
        }
    quick_sort(Apple, 0, cnt - 1);
    while (j < cnt && sum + Apple[j].y <= s) sum += Apple[j].y, j++;
    printf("%d", j), free(Apple);
    return 0;
}

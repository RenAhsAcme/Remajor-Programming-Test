//
// Created by renahsacme on 2026/4/12.
//
#include <stdio.h>
#include <stdlib.h>

struct competition {
    int begin, end;
};

void quick_sort(struct competition a[], int l, int r) {
    if (l >= r) return;
    int i = l, j = r;
    struct competition pivot = a[(l + r) / 2];
    while (i <= j) {
        while (a[i].end < pivot.end) i++;
        while (a[j].end > pivot.end) j--;
        if (i <= j) {
            struct competition tmp = a[i];
            a[i] = a[j], a[j] = tmp, i++, j--;
        }
    }
    quick_sort(a, l, j), quick_sort(a, i, r);
}

int main() {
    char buffer[1000] = {}, *next = NULL, *endptr = NULL;
    int n = 0;
    if (fgets(buffer, sizeof(buffer), stdin)) n = (int) strtol(buffer, NULL, 10);
    struct competition *Competition = calloc(n, sizeof(struct competition));
    for (int i = 0; i < n; i++)
        if (fgets(buffer, sizeof(buffer), stdin)) {
            next = buffer, Competition[i].begin = (int) strtol(next, &endptr, 10);
            next = endptr, Competition[i].end = (int) strtol(next, &endptr, 10);
        }
    quick_sort(Competition, 0, n - 1);
    int count = 0, last_end = -1;
    for (int i = 0; i < n; i++) if (Competition[i].begin >= last_end) count++, last_end = Competition[i].end;
    printf("%d", count), free(Competition);
    return 0;
}

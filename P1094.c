//
// Created by renahsacme on 2026/4/12.
//
#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *a, int l, int r) {
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
    char buffer[1000] = {};
    int w = 0, G = 0, count = 0;
    if (fgets(buffer, sizeof(buffer), stdin)) w = (int) strtol(buffer, NULL, 10);
    if (fgets(buffer, sizeof(buffer), stdin)) G = (int) strtol(buffer, NULL, 10);
    int *P = calloc(G, sizeof(int));
    for (int i = 0; i < G; i++)
        if (fgets(buffer, sizeof(buffer), stdin)) P[i] = (int) strtol(buffer, NULL, 10);
    quick_sort(P, 0, G - 1);
    for (int i = 0; i < G; i++) {
        int is_found = 0;
        for (int j = G - 1; j > i; j--)
            if (P[i] + P[j] <= w && P[i] != 0 && P[j] != 0) {
                P[i] = 0, P[j] = 0, count++, is_found = 1;
                break;
            }
        if (!is_found && P[i] != 0) count++;
    }
    printf("%d", count);
    return 0;
}

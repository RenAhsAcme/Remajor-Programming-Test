//
// Created by renahsacme on 2026/4/11.
//
#include <stdio.h>
#include <stdlib.h>

int count = 0;

int is_prime(int x) {
    if (x < 2) return 0;
    for (int i = 2; i * i <= x; i++) if (x % i == 0) return 0;
    return 1;
}

void dfs(int *a, int start, int selected_count, int sum, int n, int k) {
    if (selected_count == k) {
        if (is_prime(sum)) count++;
        return;
    }
    for (int i = start; i < n; i++) dfs(a, i + 1, selected_count + 1, sum + a[i], n, k);
}

int main() {
    char buffer[1000] = {}, *next = NULL, *endptr = NULL;
    int n = 0, k = 0;
    if (fgets(buffer, sizeof(buffer), stdin))
        next = buffer, n = (int) strtol(next, &endptr, 10), next = endptr, k = (int) strtol(next, NULL, 10);
    int *x = calloc(n, sizeof(int));
    if (fgets(buffer, sizeof(buffer), stdin)) {
        next = buffer;
        for (int i = 0; i < n; i++) x[i] = (int) strtol(next, &endptr, 10), next = endptr;
    }
    dfs(x, 0, 0, 0, n, k), printf("%d", count), free(x);
    return 0;
}

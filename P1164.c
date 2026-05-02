//
// Created by renahsacme on 2026/4/11.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    char buffer[10000] = {}, *next = NULL, *endptr = NULL;
    int N = 0, M = 0;
    if (fgets(buffer, sizeof(buffer), stdin))
        next = buffer, N = (int) strtol(next, &endptr, 10), next = endptr, M = (int) strtol(next, NULL, 10);
    int *a = calloc(N, sizeof(int));
    int *dp = calloc(10000, sizeof(int));
    if (fgets(buffer, sizeof(buffer), stdin)) {
        next = buffer;
        for (int i = 0; i < N; i++) a[i] = (int) strtol(next, &endptr, 10), next = endptr;
    }
    dp[0] = 1;
    for (int i = 0; i < N; i++) for (int j = M; j >= a[i]; j--) dp[j] += dp[j - a[i]];
    printf("%d", dp[M]), free(a), free(dp);
    return 0;
}

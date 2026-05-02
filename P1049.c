//
// Created by renahsacme on 2026/4/15.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    char buffer[1000] = {};
    int V = 0, n = 0;
    if (fgets(buffer, sizeof(buffer), stdin)) V = (int) strtol(buffer, NULL, 10);
    int *dp = calloc(V + 1, sizeof(int));
    if (fgets(buffer, sizeof(buffer), stdin)) n = (int) strtol(buffer, NULL, 10);
    int *goods = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        if (fgets(buffer, sizeof(buffer), stdin)) goods[i] = (int) strtol(buffer, NULL, 10);
    for (int i = 0; i < n; i++)
        for (int j = V; j >= goods[i]; j--)
            if (dp[j - goods[i]] + goods[i] > dp[j]) dp[j] = dp[j - goods[i]] + goods[i];
    printf("%d", V - dp[V]), free(dp), free(goods);
    return 0;
}

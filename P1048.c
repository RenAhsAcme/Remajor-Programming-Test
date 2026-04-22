//
// Created by renahsacme on 2026/4/14.
//
#include <stdio.h>
#include <stdlib.h>

struct medicine {
    int time, value;
};

int main() {
    char buffer[1000] = {}, *next = NULL, *endptr = NULL;
    int T = 0, M = 0;
    if (fgets(buffer, sizeof(buffer), stdin))
        next = buffer, T = (int) strtol(next, &endptr, 10), next = endptr, M = (int) strtol(next, NULL, 10);
    struct medicine *Medicine = calloc(M, sizeof(struct medicine));
    for (int i = 0; i < M; i++) {
        if (fgets(buffer, sizeof(buffer), stdin)) {
            next = buffer, Medicine[i].time = (int) strtol(next, &endptr, 10);
            next = endptr, Medicine[i].value = (int) strtol(next, NULL, 10);
        }
    }
    int *dp = calloc(T + 1, sizeof(int));
    for (int i = 0; i < M; i++)
        for (int j = T; j >= Medicine[i].time; j--)
            if (dp[j - Medicine[i].time] + Medicine[i].value > dp[j])
                dp[j] = dp[j - Medicine[i].time] + Medicine[i].value;
    printf("%d", dp[T]), free(Medicine), free(dp);
    return 0;
}
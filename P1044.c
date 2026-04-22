//
// Created by renahsacme on 2026/4/11.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    char buffer[1000] = {};
    long long C[20] = {0};
    int n = 0;
    if (fgets(buffer, sizeof(buffer), stdin)) n = (int) strtol(buffer, NULL, 10);
    C[0] = 1;
    for (int i = 1; i <= n; i++) for (int j = 0; j < i; j++) C[i] += C[j] * C[i - 1 - j];
    printf("%lld", C[n]);
    return 0;
}

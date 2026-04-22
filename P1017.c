//
// Created by renahsacme on 2026/4/8.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    char buffer[11] = {}, *next = NULL, *endptr = NULL;
    int n = 0, R = 0;
    if (fgets(buffer, sizeof(buffer), stdin)) {
        next = buffer, n = (int) strtol(next, &endptr, 10);
        next = endptr, R = (int) strtol(next, &endptr, 10);
    }
    if (n == 0) {
        printf("0=0(base%d)", R);
        return 0;
    }
    char res[100];
    int idx = 0, original = n;
    while (n != 0) {
        int r = n % R;
        n /= R;
        if (r < 0)
            r -= R, n += 1; // 负基制数的核心灵魂
        if (r >= 10)
            res[idx++] = (char) ('A' + r - 10);
        else
            res[idx++] = (char) ('0' + r);
    }
    printf("%d=", original);
    for (int i = idx - 1; i >= 0; i--)
        printf("%c", res[i]);
    printf("(base%d)", R);
}

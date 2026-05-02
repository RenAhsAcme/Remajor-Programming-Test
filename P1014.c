//
// Created by renahsacme on 2026/4/8.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    char buffer[9] = {};
    int n = 0, sum_temp = 0, cow = 0;
    if (fgets(buffer, sizeof(buffer), stdin)) {
        n = (int) strtol(buffer, NULL, 10);
    }
    while (sum_temp < n)
        cow++, sum_temp += cow;
    if (sum_temp == n) {
        if (cow % 2 == 0) {
            printf("%d/1", cow);
            return 0;
        } else {
            printf("1/%d", cow);
            return 0;
        }
    }
    if (sum_temp - cow + 1 == n) {
        if (cow % 2 == 0) {
            printf("1/%d", cow);
            return 0;
        } else {
            printf("%d/1", cow);
            return 0;
        }
    }
    sum_temp -= cow, n -= sum_temp;
    if (cow % 2 == 0) {
        printf("%d/%d", n, cow + 1 - n);
        return 0;
    } else {
        printf("%d/%d", cow + 1 - n, n);
        return 0;
    }
}

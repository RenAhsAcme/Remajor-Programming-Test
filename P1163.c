//
// Created by renahsacme on 2026/4/13.
//
#include <stdio.h>
#include <stdlib.h>

double check(double rate, int w_0, int w, int m) {
    double x = w_0;
    for (int i = 0; i < m; i++) x = x * (1 + rate) - w;
    return x;
}

int main() {
    char buffer[1000] = {}, *next = NULL, *endptr = NULL;
    int w_0 = 0, w = 0, m = 0;
    double l = 0, r = 3;
    if (fgets(buffer, sizeof(buffer), stdin)) {
        next = buffer, w_0 = (int) strtol(next, &endptr, 10);
        next = endptr, w = (int) strtol(next, &endptr, 10);
        next = endptr, m = (int) strtol(next, &endptr, 10);
    }
    while (r - l > 1e-6) {
        double mid = (l + r) / 2;
        if (check(mid, w_0, w, m) > 0) r = mid;
        else l = mid;
    }
    printf("%.1f", l * 100);
    return 0;
}

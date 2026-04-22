//
// Created by renahsacme on 2026/4/8.
//
#include <stdio.h>
#include <stdlib.h>

void permute(int n) {
    int power_temp = 0, result_temp = 0;
    if (n == 0)
        return;
    if (n == 1) {
        printf("2(0)");
        return;
    }
    if (n == 2) {
        printf("2");
        return;
    }
    while ((result_temp) < n)
        power_temp++, result_temp = 1 << power_temp;
    if (result_temp != n)
        power_temp -= 1, result_temp /= 2;
    if (result_temp == n) {
        printf("2(");
        permute(power_temp);
        printf(")");
        return;
    }
    if (power_temp != 0 && power_temp != 1 && power_temp != 2) {
        printf("2(");
        permute(power_temp);
        printf(")");
    }
    if (power_temp == 2)
        printf("2(2)");
    if (power_temp == 1)
        printf("2");
    if (power_temp == 0)
        printf("2(0)");
    if (result_temp < n) {
        printf("+");
        int deep = n - result_temp;
        permute(deep);
    }
}

int main() {
    int n = 0;
    char buffer[6] = {};
    if (fgets(buffer, sizeof(buffer), stdin))
        n = (int) strtol(buffer, NULL, 10);
    permute(n);
}

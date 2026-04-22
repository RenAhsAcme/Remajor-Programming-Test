//
// Created by renahsacme on 2026/4/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n = 0, fact[1000] = {1}, sum[1000] = {0}, fact_len = 1, sum_len = 1;
    char buffer[3] = {};
    if (fgets(buffer, sizeof(buffer), stdin))
        n = (int) strtol(buffer, NULL, 10);
    for (int i = 1; i <= n; i++) {
        // ---------- fact *= i ----------
        int carry = 0;
        for (int j = 0; j < fact_len; j++) {
            int temp = fact[j] * i + carry;
            fact[j] = temp % 10, carry = temp / 10;
        }
        while (carry)
            fact[fact_len++] = carry % 10, carry /= 10;
        // ----------- sum *= fact ----------
        carry = 0;
        int max_len = fact_len > sum_len ? fact_len : sum_len;
        for (int j = 0; j < max_len; j++) {
            int temp = sum[j] + (j < fact_len ? fact[j] : 0) + carry;
            sum[j] = temp % 10, carry = temp / 10;
        }
        sum_len = max_len;
        if (carry)
            sum[sum_len++] = carry;
    }
    for (int i = sum_len - 1; i >= 0; i--)
        printf("%d", sum[i]);
    printf("\n");
    return 0;
}

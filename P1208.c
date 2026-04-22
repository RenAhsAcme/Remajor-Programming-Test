//
// Created by renahsacme on 2026/4/12.
//
#include <stdio.h>
#include <stdlib.h>

struct farmer {
    int price, num;
};

void quick_sort(struct farmer *a, int l, int r) {
    if (l >= r) return;
    int i = l, j = r;
    struct farmer pivot = a[(l + r) / 2];
    while (i <= j) {
        while (a[i].price < pivot.price) i++;
        while (a[j].price > pivot.price) j--;
        if (i <= j) {
            struct farmer tmp = a[i];
            a[i] = a[j], a[j] = tmp, i++, j--;
        }
    }
    quick_sort(a, l, j);
    quick_sort(a, i, r);
}

int main() {
    char buffer[100000] = {}, *next = NULL, *endptr = NULL;
    int n = 0, m = 0;
    if (fgets(buffer, sizeof(buffer), stdin))
        next = buffer, n = (int) strtol(next, &endptr, 10), next = endptr, m = (int) strtol(next, NULL, 10);
    struct farmer *Farmer = calloc(m, sizeof(struct farmer));
    for (int i = 0; i < m; i++)
        if (fgets(buffer, sizeof(buffer), stdin)) {
            next = buffer, Farmer[i].price = (int) strtol(next, &endptr, 10);
            next = endptr, Farmer[i].num = (int) strtol(next, NULL, 10);
        }
    quick_sort(Farmer, 0, m - 1);
    long long sum = 0, count = 0;
    int i = 0;
    while (sum < n) sum += Farmer[i].num, i++;
    i -= 1;
    long long prev_sum = sum - Farmer[i].num;
    for (int j = 0; j < i; j++) count += Farmer[j].price * Farmer[j].num;
    count += Farmer[i].price * (n - prev_sum), printf("%lld\n", count);
    return 0;
}

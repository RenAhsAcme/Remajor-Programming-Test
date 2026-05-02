//
// Created by renahsacme on 2026/4/12.
//
#include <stdio.h>
#include <stdlib.h>

struct waiter {
    int No, time, wait_time;
};

int cmp(struct waiter a, struct waiter b) {
    if (a.time != b.time) return a.time < b.time;
    return a.No < b.No;
}

void quick_sort(struct waiter a[], int l, int r) {
    if (l >= r) return;
    int i = l, j = r;
    struct waiter pivot = a[(l + r) / 2];
    while (i <= j) {
        while (cmp(a[i], pivot)) i++;
        while (cmp(pivot, a[j])) j--;
        if (i <= j) {
            struct waiter tmp = a[i];
            a[i] = a[j], a[j] = tmp, i++, j--;
        }
    }
    quick_sort(a, l, j), quick_sort(a, i, r);
}

int main() {
    char buffer[100000] = {}, *next = NULL, *endptr = NULL;
    int n = 0;
    double sum = 0;
    if (fgets(buffer, sizeof(buffer), stdin)) n = (int) strtol(buffer, NULL, 10);
    struct waiter *Waiter = calloc(n, sizeof(struct waiter));
    if (fgets(buffer, sizeof(buffer), stdin)) {
        next = buffer;
        for (int i = 0; i < n; i++)
            Waiter[i].No = i + 1, Waiter[i].time = (int) strtol(next, &endptr, 10), next = endptr;
    }
    quick_sort(Waiter, 0, n - 1);
    for (int i = 1; i < n; i++)
        Waiter[i].wait_time = Waiter[i - 1].wait_time + Waiter[i - 1].time;
    for (int i = 0; i < n; i++) printf("%d ", Waiter[i].No), sum += Waiter[i].wait_time;
    double average = sum / n;
    printf("\n%.2f", average);
    return 0;
}

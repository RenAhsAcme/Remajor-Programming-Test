//
// Created by renahsacme on 2026/4/9.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct employee {
    int k, s;
    bool available;
};

void quick_sort(struct employee a[], int l, int r) {
    if (l >= r) return;
    int i = l, j = r, pivot = a[(l + r) / 2].s;
    while (i <= j) {
        while (a[i].s > pivot) i++;
        while (a[j].s < pivot) j--;
        if (i <= j) {
            struct employee tmp = a[i];
            a[i] = a[j], a[j] = tmp, i++, j--;
        }
    }
    quick_sort(a, l, j), quick_sort(a, i, r);
}

int main() {
    char buffer[11] = {}, *next = NULL, *endptr = NULL;
    int n = 0, m = 0;
    if (fgets(buffer, sizeof(buffer), stdin))
        next = buffer, n = (int) strtol(next, &endptr, 10), next = endptr, m = (int) strtol(next, NULL, 10);
    struct employee Employee[n] = {};
    strcpy(buffer, "");
    for (int i = 0; i < n; i++)
        if (fgets(buffer, sizeof(buffer), stdin)) {
            next = buffer, Employee[i].k = (int) strtol(next, &endptr, 10);
            next = endptr, Employee[i].s = (int) strtol(next, NULL, 10);
        }
    quick_sort(Employee, 0, n - 1);
    int wanted = (int) (m * 1.5);
    for (int i = 0; i < wanted; i++)
        Employee[i].available = true;
    for (int i = wanted; i < n; i++)
        if (Employee[i].s == Employee[wanted - 1].s)
            wanted++, Employee[i].available = true;
        else
            break;
    printf("%d %d\n", Employee[wanted - 1].s, wanted);
    fflush(stdout);
    for (int i = 0; i < wanted; i++)
        if (Employee[i].available == true) {
            for (int j = i + 1; j < wanted; j++)
                if (Employee[j].s == Employee[i].s && Employee[j].k < Employee[i].k) {
                    struct employee tmp = Employee[j];
                    Employee[j] = Employee[i], Employee[i] = tmp;
                }
            printf("%d %d\n", Employee[i].k, Employee[i].s);
            fflush(stdout);
        } else
            break;
    return 0;
}

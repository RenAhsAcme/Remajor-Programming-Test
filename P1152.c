//
// Created by renahsacme on 2026/4/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void quick_sort(int *number, int l, int r) {
    if (l >= r) return;
    int i = l, j = r, pivot = number[(l + r) / 2];
    while (i <= j) {
        while (number[i] > pivot) i++;
        while (number[j] < pivot) j--;
        if (i <= j) {
            int tmp = number[i];
            number[i] = number[j], number[j] = tmp, i++, j--;
        }
    }
    quick_sort(number, l, j), quick_sort(number, i, r);
}

int main() {
    char buffer[20000] = {}, *next = NULL, *endptr = NULL;
    int dig_num = 0, *number;
    if (fgets(buffer, sizeof(buffer), stdin)) {
        dig_num = (int) strtol(buffer, &endptr, 10), next = endptr;
        number = calloc(dig_num, sizeof(int));
        for (int i = 0; i < dig_num; i++) number[i] = (int) strtol(next, &endptr, 10), next = endptr;
    }
    int *jolly_num = calloc(dig_num - 1, sizeof(int));
    for (int i = 0; i < dig_num - 1; i++)
        jolly_num[i] = number[i + 1] - number[i] > 0 ? number[i + 1] - number[i] : number[i] - number[i + 1];
    bool is_jolly = true;
    quick_sort(jolly_num, 0, dig_num - 2);
    for (int i = 0; i < dig_num - 1; i++) {
        if (jolly_num[i + 1] - jolly_num[i] == -1) continue;
        is_jolly = false;
        break;
    }
    if (is_jolly) printf("Jolly");
    else printf("Not jolly");
    free(number), free(jolly_num);
    return 0;
}

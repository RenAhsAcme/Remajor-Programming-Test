//
// Created by renahsacme on 2026/4/7.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char (*result)[12];
int count = 0;

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b, *b = temp;
}

void permute(char *arr, int left, int right) {
    if (left == right) {
        strcpy(result[count], arr);
        result[count][11] = '\0', count++;
        return;
    }
    for (int i = left; i <= right; i++) {
        swap(&arr[i], &arr[left]);
        permute(arr, left + 1, right);
        swap(&arr[i], &arr[left]);
    }
}

int main() {
    result = malloc(362880 * sizeof(*result));
    char arr[12] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};
    permute(arr, 0, 8);
    for (int i = 0; i < count; i++) {
        char newstr[12] = {};
        snprintf(newstr, sizeof(newstr), "%.3s %.3s %.3s", result[i], result[i] + 3, result[i] + 6);
        strcpy(result[i], newstr);
    }
    for (int i = 0; i < count; i++) {
        char *next = result[i], *endptr = NULL;
        int a = (int) strtol(next, &endptr, 10);
        next = endptr;
        int b = (int) strtol(next, &endptr, 10);
        next = endptr;
        int c = (int) strtol(next, &endptr, 10);
        if (b == a * 2 && c == a * 3)
            printf("%d %d %d\n", a, b, c);
    }
    return 0;
}

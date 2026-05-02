//
// Created by renahsacme on 2026/4/12.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char buffer[1000] = {}, *next = NULL;
    char n[270] = {}, result[270] = {};
    int k = 0, i = 0, j = 0, l = 0, found_num = 0, start = 0;
    if (fgets(buffer, sizeof(buffer), stdin)) {
        next = buffer;
        while (*next != '\n' && *next != '\r') next++;
        *next = '\0', strcpy(n, buffer);
    }
    int n_len = (int) strlen(n);
    if (fgets(buffer, sizeof(buffer), stdin)) k = (int) strtol(buffer, NULL, 10);
    int asked_len = n_len - k;
    while (found_num < asked_len) {
        int limit = n_len - (asked_len - found_num), min_pos = i;
        for (j = i; j <= limit; j++) if (n[j] < n[min_pos]) min_pos = j;
        result[l++] = n[min_pos], found_num++, i = min_pos + 1;
    }
    while (start < asked_len - 1 && result[start] == '0') start++;
    for (int m = start; m < asked_len; m++) printf("%c", result[m]);
    return 0;
}

//
// Created by renahsacme on 2026/4/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    char buffer[1000] = {}, *next = NULL, *endptr = NULL;
    int sum = 0, input_count = 0, count = 0, j = 0;
    bool out_break = false, has_operation = true;
    if (fgets(buffer, sizeof(buffer), stdin)) sum = (int) strtol(buffer, NULL, 10);
    int *origin_sequence = calloc(sum, sizeof(int));
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin)) {
            next = buffer;
            for (; j < sum; ) {
                if (input_count == sum) {
                    out_break = true;
                    break;
                }
                if (*next == '\n' || *next == '\0')
                    break;
                int val = (int) strtol(next, &endptr, 10);
        // 防御性编程注意：防止指针在遇到极端情况下不移动 ==============================================================
                if (next == endptr) {
                    next++;
                    continue;
                }
                origin_sequence[j] = val, next = endptr, input_count++, j++;
            }
        } else break;
        // =====================================================================================================
        if (out_break) break;
    }
    while (has_operation) {
        has_operation = false;
        for (int i = 0; i < sum - 1; i++)
            if (origin_sequence[i] > origin_sequence[i + 1]) {
                int tmp = origin_sequence[i];
                origin_sequence[i] = origin_sequence[i + 1], origin_sequence[i + 1] = tmp, count++;
                has_operation = true;
            }
    }
    printf("%d", count), free(origin_sequence);
    return 0;
}

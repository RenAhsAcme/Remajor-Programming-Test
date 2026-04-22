//
// Created by renahsacme on 2026/4/8.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n = 0, count = 0;
    char buffer[101] = {}, m[1000] = {}, result[1000] = {};
    if (fgets(buffer, sizeof(buffer), stdin))
        n = (int) strtol(buffer, NULL, 10);
    if (fgets(buffer, sizeof(buffer), stdin)) {
        strcpy(m, buffer);
        int again_begin = 0, str_len = 0, carry = 0, i = 0;
        again:
        memset(result, 0, sizeof(result));
        if (again_begin)
            str_len = (int) strlen(m), carry = 0;
        else
            str_len = (int) strlen(m) - 1, carry = 0;
        for (i = str_len - 1; i >= 0 ; i--) {
            int cache = m[str_len - 1 - i] - '0' + (m[i] - '0') + carry;
            carry = 0;
            if (cache >= n) {
                carry = 1, result[str_len - 1 - i] = (char) ((cache % n) + '0');
                continue;
            }
            result[str_len - 1 - i] = (char) (cache + '0');
        }
        if (carry > 0)
            result[str_len - 1 - i] = '1', carry = 0;
        result[str_len + 1] = '\0';
        int str_len_result = (int) strlen(result), found = 0;
        for (int j = 0; j < str_len_result; j++)
            if (result[j] != result[str_len_result - 1 - j]) {
                found = 1, count++;
                break;
            }
        if (!found)
            printf("STEP=%d\n", ++count);
        else {
            strcpy(m, result);
            again_begin = 1;
            if (count < 30)
                goto again;
            else
                printf("Impossible!");
        }
    }
    return 0;
}
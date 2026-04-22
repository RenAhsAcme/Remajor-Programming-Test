//
// Created by renahsacme on 2026/4/11.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 高精度加法的典型实现方法（我自己实现的）====================================================================================
void high_precision_addition(char *result, char *addend_1, char *addend_2) {
    int addend_1_length = (int) strlen(addend_1), addend_2_length = (int) strlen(addend_2), need_len = 0, extra_len = 0;
    if (addend_1_length < addend_2_length) need_len = addend_1_length, extra_len = addend_2_length - need_len;
    if (addend_1_length > addend_2_length) need_len = addend_2_length, extra_len = addend_1_length - need_len;
    if (addend_1_length == addend_2_length) need_len = addend_1_length;
    int carry = 0, k = 0;
    for (; k < need_len; k++) {
        int tmp = addend_1[k] - '0' + addend_2[k] - '0' + carry;
        if (tmp >= 10) carry = 1, result[k] = (char) (tmp - 10 + '0');
        else carry = 0, result[k] = (char) (tmp + '0');
    }
    for (k = need_len; k < need_len + extra_len; k++) {
        int tmp = addend_1_length > addend_2_length ? addend_1[k] - '0' + carry : addend_2[k] - '0' + carry;
        if (tmp >= 10) carry = 1, result[k] = (char) (tmp - 10 + '0');
        else carry = 0, result[k] = (char) (tmp + '0');
    }
    if (carry == 1) result[k] = '1';
}
// =====================================================================================================================

int main() {
    char buffer[1000] = {};
    int N = 0;
    if (fgets(buffer, sizeof(buffer), stdin)) N = (int) strtol(buffer, NULL, 10);
    char (*p)[1500] = calloc(N, sizeof(char [1500]));
    strcpy(p[0], "1"), strcpy(p[1], "2");
    for (int i = 2; i < N; i++) high_precision_addition(p[i], p[i - 1], p[i - 2]);
    for (int i = (int) strlen(p[N - 1]) - 1; i >= 0; i--) printf("%c", p[N - 1][i]);
    free(p);
    return 0;
}

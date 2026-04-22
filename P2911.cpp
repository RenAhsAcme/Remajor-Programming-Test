//
// Created by RenAhsAcme on 2026/4/17.
//
#include <iostream>
using namespace std;

void quick_sort(int *a, int l, int r) {
    if (l >= r) return;
    int i = l, j = r, pivot = a[(l + r) / 2];
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            int tmp = a[i];
            a[i] = a[j], a[j] = tmp, i++, j--;
        }
    }
    quick_sort(a, l, j), quick_sort(a, i, r);
}

int main() {
    int s_1 = 0, s_2 = 0, s_3 = 0, l = 0;
    cin >> s_1 >> s_2 >> s_3;
    int result_len = s_1 * s_2 * s_3;
    int *result = new int[result_len];
    for (int i = 1; i <= s_1; i++)
        for (int j = 1; j <= s_2; j++) for (int k = 1; k <= s_3; k++) result[l++] = i + j + k;
    quick_sort(result, 0, result_len - 1);
    int challenge = 1, expected_result = 0, count = 1;
    for (int i = 1; i < result_len; i++) {
        if (result[i] == result[i - 1]) count++;
        if (result[i] != result[i - 1]) count = 1;
        if (count > challenge) challenge = count, expected_result = result[i];
    }
    cout << expected_result;
    delete [] result;
    return 0;
}

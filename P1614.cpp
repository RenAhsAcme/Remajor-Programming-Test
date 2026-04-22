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
    int n = 0, m = 0, j = 0;
    cin >> n >> m;
    int *a = new int[n](), *sum = new int[n - m + 1]();
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = m - 1; i < n; i++) {
        for (int k = 0; k < m; k++) sum[j] += a[i - k];
        j++;
    }
    quick_sort(sum, 0, n - m), cout << sum[0];
    delete [] a;
    delete [] sum;
    return 0;
}

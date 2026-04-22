//
// Created by RenAhsAcme on 2026/4/16.
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
    int n = 0;
    cin >> n;
    int *N = new int[n];
    for (int i = 0; i < n; i++) cin >> N[i];
    quick_sort(N, 0, n - 1);
    double ans = 0;
    for (int i = 1; i < n - 1; i++) ans += N[i] * (1.0 / (n - 2));
    printf("%.2f", ans);
    delete[] N;
    return 0;
}

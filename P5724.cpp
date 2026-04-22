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
    int *a = new int[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    quick_sort(a, 0, n - 1);
    cout << a[n - 1] - a[0];
    free(a);
    return 0;
}

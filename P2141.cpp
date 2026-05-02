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
    int *t = new int[n](), count = 0;
    for (int i = 0; i < n; i++) cin >> t[i];
    quick_sort(t, 0, n - 1);
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (i == k) continue;
            for (int j = i + 1; j < n; j++) {
                if (j == k) continue;
                if (t[i] + t[j] == t[k]) {
                    count++;
                    goto next_k;
                }
            }
        }
    next_k:;
    }
    cout << count;
    delete [] t;
    return 0;
}

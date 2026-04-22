//
// Created by RenAhsAcme on 2026/4/15.
//
#include <iostream>
#include <cmath>
using namespace std;

void quick_sort(int a[], int l, int r) {
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
    int side[3] = {};
    cin >> side[0] >> side[1] >> side[2];
    quick_sort(side, 0, 2);
    if (side[0] + side[1] > side[2]) {
        double right = pow(side[0], 2) + pow(side[1], 2) - pow(side[2], 2);
        if (0 <= right && right < 1e-6) printf("Right triangle\n");
        if (pow(side[0], 2) + pow(side[1], 2) > pow(side[2], 2)) printf("Acute triangle\n");
        if (pow(side[0], 2) + pow(side[1], 2) < pow(side[2], 2)) printf("Obtuse triangle\n");
        if (side[0] == side[1] || side[1] == side[2]) printf("Isosceles triangle\n");
        if (side[0] == side[1] && side[1] == side[2]) printf("Equilateral triangle");
    } else cout << "Not triangle";
}

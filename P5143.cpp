//
// Created by RenAhsAcme on 2026/4/21.
//
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct dot {
    int x, y, z;
};

void quick_sort(vector<dot> &Dot, int l, int r) {
    if (l >= r) return;
    int i = l, j = r;
    dot pivot = Dot[(l + r) / 2];
    while (i <= j) {
        while (Dot[i].z < pivot.z) i++;
        while (Dot[j].z > pivot.z) j--;
        if (i <= j) {
            dot tmp = Dot[i];
            Dot[i] = Dot[j], Dot[j] = tmp, i++, j--;
        }
    }
    quick_sort(Dot, l, j), quick_sort(Dot, i, r);
}

int main() {
    int N = 0;
    cin >> N;
    vector<dot> Dot(N);
    for (int i = 0; i < N; i++) {
        cin >> Dot[i].x >> Dot[i].y >> Dot[i].z;
    }
    quick_sort(Dot, 0, N - 1);
    double sum = 0;
    for (int i = 0; i < N - 1; i++) {
        sum += sqrt(
            pow(Dot[i].x - Dot[i + 1].x, 2) + pow(Dot[i].y - Dot[i + 1].y, 2)
            + pow(Dot[i].z - Dot[i + 1].z, 2));
    }
    printf("%.3f", sum);
    return 0;
}

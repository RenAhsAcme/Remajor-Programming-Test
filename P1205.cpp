//
// Created by RenAhsAcme on 2026/4/18.
//
#include <iostream>
using namespace std;

int n = 0;
char a[15][15] = {}, b[15][15] = {};

bool same(char x[15][15], char y[15][15]) {
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (x[i][j] != y[i][j]) return false;
    return true;
}

void rotate90(char src[15][15], char dst[15][15]) {
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dst[i][j] = src[n - 1 - j][i];
}

void reflect(char src[15][15], char dst[15][15]) {
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dst[i][j] = src[i][n - 1 - j];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    char t1[15][15] = {}, t2[15][15] = {};
    rotate90(a, t1);
    if (same(t1, b)) {
        cout << 1;
        return 0;
    }
    rotate90(t1, t2);
    if (same(t2, b)) {
        cout << 2;
        return 0;
    }
    rotate90(t2, t1);
    if (same(t1, b)) {
        cout << 3;
        return 0;
    }
    reflect(a, t1);
    if (same(t1, b)) {
        cout << 4;
        return 0;
    }
    rotate90(t1, t2);
    if (same(t2, b)) {
        cout << 5;
        return 0;
    }
    rotate90(t2, t1);
    if (same(t1, b)) {
        cout << 5;
        return 0;
    }
    rotate90(t1, t2);
    if (same(t2, b)) {
        cout << 5;
        return 0;
    }
    if (same(a, b)) {
        cout << 6;
        return 0;
    }
    cout << 7;
    return 0;
}

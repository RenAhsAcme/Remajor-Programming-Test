//
// Created by RenAhsAcme on 2026/4/16.
//
#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    for (int i = 100; i >= 1; i--)
        for (int j = 1; 364 * i + 1092 * j <= n; j++)
            if (364 * i + 1092 * j == n) {
                cout << i << endl << j;
                return 0;
            }
}

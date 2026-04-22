//
// Created by RenAhsAcme on 2026/4/17.
//
#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    if (n == 1) {
        cout << "1";
        return 0;
    }
    if (n == 2) {
        cout << "1" << endl << "1 1";
        return 0;
    }
    int result[n][n];
    result[0][0] = 1, result[1][0] = 1, result[1][1] = 1;
    for (int i = 2; i < n; i++) {
        result[i][0] = 1, result[i][i] = 1;
        for (int j = 1; j < i; j++) result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}

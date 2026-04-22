//
// Created by RenAhsAcme on 2026/4/16.
//
#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) {
            cout << n / i;
            return 0;
        }
}

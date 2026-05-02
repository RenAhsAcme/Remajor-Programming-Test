//
// Created by RenAhsAcme on 2026/4/19.
//
#include <iostream>
using namespace std;

int main() {
    int n = 0, ans = 1;
    cin >> n;
    for (int i = 0; i < n - 1; i++) ans = (ans + 1) * 2;
    cout << ans;
    return 0;
}

//
// Created by RenAhsAcme on 2026/4/22.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n = 0;
    long long cnt = 0;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n / 2; i++)
        cnt += static_cast<long long>(pow(a[n - i] - a[i], 2) + pow(a[i + 1] - a[n - i], 2));
    if (n % 2 != 0) cnt += static_cast<long long>(pow((a[n / 2] - a[n / 2 + 1]), 2));
    cout << cnt;
    return 0;
}

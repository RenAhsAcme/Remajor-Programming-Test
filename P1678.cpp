//
// Created by RenAhsAcme on 2026/4/22.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int m = 0, n = 0;
    long long sum = 0;
    cin >> m >> n;
    vector<int> a(m, 0);
    vector<int> b(n, 0);
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        int x = b[i];
        auto it = lower_bound(a.begin(), a.end(), x);
        long long best = 1e9;
        if (it != a.end()) best = min(best, llabs(*it - x));
        if (it != a.begin()) it--, best = min(best, llabs(*it - x));
        sum += best;
    }
    cout << sum;
    return 0;
}

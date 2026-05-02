//
// Created by RenAhsAcme on 2026/4/22.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n = 0, k = 0;
vector<int> L;

bool check(int x) {
    if (x == 0) return true;
    int tmp_sum = 0;
    for (int i = 0; i < n; i++) tmp_sum += L[i] / x;
    return tmp_sum >= k;
}

int main() {
    cin >> n >> k;
    L.resize(n);
    for (int i = 0; i < n; i++) cin >> L[i];
    sort(L.begin(), L.end());
    int l = 1, r = L.back(), ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}

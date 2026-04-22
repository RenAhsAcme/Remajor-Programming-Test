//
// Created by RenAhsAcme on 2026/4/22.
//
#include <iostream>
#include <vector>
using namespace std;
int L = 0, N = 0, K = 0;
vector<int> a;

bool check(int x) {
    if (x == 0) return false;
    int need = 0;
    for (int i = 1; i < N; i++) {
        int gap = a[i] - a[i - 1];
        need += (gap - 1) / x;
    }
    return need <= K;
}

int main() {
    cin >> L >> N >> K;
    a.resize(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    int l = 0, r = L, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}

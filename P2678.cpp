//
// Created by RenAhsAcme on 2026/4/22.
//
#include <iostream>
#include <vector>
using namespace std;

int L, N, M;
vector<int> d;

bool check(int x) {
    int last = 0, removed = 0;
    for (int i = 0; i < N; i++)
        if (d[i] - last < x) removed++;
        else last = d[i];
    if (L - last < x) removed++;
    return removed <= M;
}

int main() {
    cin >> L >> N >> M;
    d.resize(N);
    for (int i = 0; i < N; i++) cin >> d[i];
    int l = 0, r = L, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}

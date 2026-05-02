//
// Created by RenAhsAcme on 2026/4/22.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n = 0, x = 0;
    long long cnt = 0;
    cin >> n >> x;
    vector<int> candy(n, 0);
    for (int i = 0; i < n; i++) cin >> candy[i];
    for (int i = 0; i < n - 1; i++) {
        if (candy[i] > x) cnt += candy[i] - x, candy[i] = x;
        if (candy[i] + candy[i + 1] > x)
            cnt += candy[i] + candy[i + 1] - x, candy[i + 1] -= candy[i] + candy[i + 1] - x;
    }
    cout << cnt;
    return 0;
}

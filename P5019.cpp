//
// Created by RenAhsAcme on 2026/4/22.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n = 0, cnt = 0, zero_num = 0;
    cin >> n;
    vector<int> d(n, 0);
    for (int i = 0; i < n; i++) cin >> d[i];
    auto begin = d.begin(), end = d.end();
    while (zero_num != n) {
        auto it = find(begin, end, 0);
        for (auto i = begin; i < end; ++i) *i -= 1;
        cnt++;
        auto tmp = find(begin, end, 0);
        if (tmp != it) end = tmp;
        if (end == begin) {
            while (*end == 0 && end != d.end()) ++begin, ++end, zero_num++;
            while (*end != 0 && end != d.end()) ++end;
        }
    }
    cout << cnt;
    return 0;
}

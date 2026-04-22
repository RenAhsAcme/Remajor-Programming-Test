//
// Created by RenAhsAcme on 2026/4/22.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x = 0, n = 0, cnt = 0;
    cin >> x >> n;
    vector<int> length(8, 250);
    length[6] = length[7] = length[0] = 0;
    for (int i = x; i < x + n; i++)
        if (i <= 7) cnt += length[i];
        else cnt += length[i % 7];
    cout << cnt;
}

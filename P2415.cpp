//
// Created by RenAhsAcme on 2026/4/19.
//
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    vector<int> all;
    int x = 0;
    while (cin >> x) all.push_back(x);
    long long sum = 0;
    for (int i = 0; i < all.size(); i++) sum += all[i];
    auto core = static_cast<long long>(pow(2, all.size() - 1));
    cout << core * sum;
    return 0;
}

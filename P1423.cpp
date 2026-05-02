//
// Created by RenAhsAcme on 2026/4/16.
//
#include <iostream>
using namespace std;

int main() {
    double s = 0, has_swum = 0, force = 2;
    int times = 0;
    cin >> s;
    while (has_swum + force < s)
        has_swum += force, force *= 0.98, times++;
    times++;
    cout << times;
}

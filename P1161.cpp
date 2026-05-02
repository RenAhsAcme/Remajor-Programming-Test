//
// Created by RenAhsAcme on 2026/4/17.
//
#include <iostream>
using namespace std;

int main() {
    int n = 0, *lamp = new int[2000001]();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t = 0;
        double a = 0;
        cin >> a >> t;
        for (int j = 1; j <= t; j++) lamp[static_cast<int>(a * j)] = lamp[static_cast<int>(a * j)] == 1 ? 0 : 1;
    }
    for (int i = 1; i <= 2000000; i++)
        if (lamp[i] == 1) {
            cout << i;
            delete [] lamp;
            return 0;
        }
}

//
// Created by RenAhsAcme on 2026/4/16.
//
#include <iostream>
using namespace std;

int main() {
    int *a = new int[12];
    for (int i = 0; i < 12; i++) {
        int tmp = 0;
        cin >> tmp, a[i] = 300 - tmp;
    }
    int mom = 0, sum = 0, i = 0;
    for (i = 0; i < 12; i++) {
        sum += a[i];
        while (sum >= 100) sum -= 100, mom += 100;
        if (sum < 0) {
            cout << '-' << i + 1;
            delete [] a;
            return 0;
        }
    }
    cout << mom * 1.2 + sum;
    delete [] a;
    return 0;
}

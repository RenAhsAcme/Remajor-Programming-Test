//
// Created by RenAhsAcme on 2026/4/16.
//
#include <iostream>
using namespace std;

int main() {
    int n = 0, challenge = 1, count = 1;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++)
        if (a[i] - a[i - 1] == 1) {
            count++;
            if (count > challenge) challenge = count;
        } else count = 1;
    cout << challenge, free(a);
    return 0;
}

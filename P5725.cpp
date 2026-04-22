//
// Created by RenAhsAcme on 2026/4/16.
//
#include <iostream>
using namespace std;

int main() {
    int n = 0, cur = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%02d", cur++);
        cout << endl;
    }
    cout << endl, cur = 1;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n - 1 - i; k++) printf("  ");
        for (int j = 0; j < i + 1; j++) printf("%02d", cur++);
        printf("\n");
    }
    return 0;
}

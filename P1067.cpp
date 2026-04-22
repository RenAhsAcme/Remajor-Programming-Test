//
// Created by RenAhsAcme on 2026/4/19.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int tmp = 0;
    cin >> tmp;
    int n = tmp + 1;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    bool has_first = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;
        if (!has_first && a[i] != 0) {
            if (n - 1 - i == 0) {
                cout << a[i];
                return 0;
            }
            if (n - 1 - i == 1)
                if (a[i] == 1) cout << "x";
                else if (a[i] == -1) cout << "-x";
                else cout << a[i] << "x";
            else if (a[i] == 1) cout << "x^" << n - 1 - i;
            else if (a[i] == -1) cout << "-x^" << n - 1 - i;
            else cout << a[i] << "x^" << n - 1 - i;
            has_first = true;
            continue;
        }
        if (has_first && i == n - 1) {
            if (a[i] > 0) cout << "+" << a[i];
            else cout << a[i];
            break;
        }
        if (has_first && n - 1 - i == 1) {
            if (a[i] > 0)
                if (a[i] != 1) cout << "+" << a[i] << "x";
                else cout << "+x";
            else cout << a[i] << "x";
            continue;
        }
        if (a[i] > 0) {
            if (a[i] == 1) cout << "+x^" << n - 1 - i;
            else cout << "+" << a[i] << "x^" << n - 1 - i;
        }
        if (a[i] < 0) {
            if (a[i] == -1) cout << "-x^" << n - 1 - i;
            else cout << a[i] << "x^" << n - 1 - i;
        }
    }
    return 0;
}

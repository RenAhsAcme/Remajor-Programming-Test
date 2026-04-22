//
// Created by RenAhsAcme on 2026/4/18.
//
#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    string s = " ";
    cin >> s;
    int ptr = 0, cnt = 0;
    while (s.find("VK", ptr) != -1) ptr = static_cast<int>(s.find("VK", ptr)) + 2, cnt++;
    for (int i = 0; i < n - 1; i++)
        if (s[i] == s[i + 1]) {
            bool used = false;
            if (i > 0 && s[i - 1] == 'V' && s[i] == 'K') used = true;
            if (i < n - 2 && s[i] == 'V' && s[i + 1] == 'K') used = true;
            if (!used) {
                cnt++;
                break;
            }
        }
    cout << cnt;
}

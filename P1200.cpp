//
// Created by RenAhsAcme on 2026/4/18.
//
#include <iostream>
using namespace std;

int main() {
    string s1 = " ", s2 = " ";
    cin >> s1, cin >> s2;
    int sum = 1, ans1 = 0, ans2 = 0;
    for (int i = 0; i < s1.length(); i++) sum *= s1[i] - 'A' + 1;
    ans1 = sum % 47, sum = 1;
    for (int i = 0; i < s2.length(); i++) sum *= s2[i] - 'A' + 1;
    ans2 = sum % 47;
    if (ans1 == ans2) cout << "GO";
    else cout << "STAY";
    return 0;
}

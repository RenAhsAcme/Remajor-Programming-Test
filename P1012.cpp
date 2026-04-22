//
// Created by RenAhsAcme on 2026/4/21.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

int main() {
    int n = 0;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s.begin(), s.end(), cmp);
    for (int i = 0; i < n; i++) cout << s[i];
    return 0;
}

//
// Created by RenAhsAcme on 2026/4/18.
//
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool printed = false;
    if (s.find(".") != string::npos) {
        auto ptr = s.find(".");
        int has_left_zero = 0;
        for (int i = static_cast<int>(ptr) - 1; i >= 0; i--) {
            if (s[i] != '0') has_left_zero = 1, cout << s[i], printed = true;
            if (s[i] == '0' && has_left_zero) cout << s[i], printed = true;
        }
        if (!printed) cout << "0";
        cout << ".";
        while (s[ptr + 1] == '0') s.erase(ptr + 1, 1);
        for (int i = static_cast<int>(s.length()) - 1; i > ptr; i--) cout << s[i];
        if (ptr == s.length() - 1) cout << "0";
        return 0;
    }
    if (s.find("/") != string::npos) {
        auto ptr = s.find("/");
        int has_left_zero = 0;
        for (int i = static_cast<int>(ptr) - 1; i >= 0; i--) {
            if (s[i] != '0') has_left_zero = 1, cout << s[i], printed = true;
            if (s[i] == '0' && has_left_zero) cout << s[i], printed = true;
        }
        if (!printed) cout << "0";
        cout << "/";
        int has_right_zero = 0;
        for (int i = static_cast<int>(s.length()) - 1; i > ptr; i--) {
            if (s[i] != '0') has_right_zero = 1, cout << s[i];
            if (s[i] == '0' && has_right_zero) cout << s[i];
        }
        if (!has_right_zero) cout << '0';
        return 0;
    }
    if (s.find("%") != string::npos) {
        auto ptr = s.find("%");
        int has_left_zero = 0;
        for (int i = static_cast<int>(ptr) - 1; i >= 0; i--) {
            if (s[i] != '0') has_left_zero = 1, cout << s[i], printed = true;
            if (s[i] == '0' && has_left_zero) cout << s[i], printed = true;
        }
        if (!printed) cout << "0";
        cout << "%";
        return 0;
    }
    int has_left_zero = 0;
    for (int i = static_cast<int>(s.length()) - 1; i >= 0; i--) {
        if (s[i] != '0') has_left_zero = 1, cout << s[i], printed = true;
        if (s[i] == '0' && has_left_zero) cout << s[i], printed = true;
    }
    if (!printed) cout << "0";
    return 0;
}

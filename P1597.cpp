//
// Created by RenAhsAcme on 2026/4/18.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = " ";
    cin >> s;
    int ptr = 1, a = 0, b = 0, c = 0;
    while (ptr < s.length() && s.find(":=", ptr) != string::npos) {
        int ptr_tmp = static_cast<int>(s.find(":=", ptr));
        if (s[ptr_tmp - 1] == 'a') {
            if (s[ptr_tmp + 2] == 'a') {
            } else if (s[ptr_tmp + 2] == 'b') a = b;
            else if (s[ptr_tmp + 2] == 'c') a = c;
            else a = s[ptr_tmp + 2] - '0';
        }
        if (s[ptr_tmp - 1] == 'b') {
            if (s[ptr_tmp + 2] == 'a') b = a;
            else if (s[ptr_tmp + 2] == 'b') {
            } else if (s[ptr_tmp + 2] == 'c') b = c;
            else b = s[ptr_tmp + 2] - '0';
        }
        if (s[ptr_tmp - 1] == 'c') {
            if (s[ptr_tmp + 2] == 'a') c = a;
            else if (s[ptr_tmp + 2] == 'b') c = b;
            else if (s[ptr_tmp + 2] == 'c') {
            } else c = s[ptr_tmp + 2] - '0';
        }
        ptr += 5;
    }
    cout << a << " " << b << " " << c;
    return 0;
}

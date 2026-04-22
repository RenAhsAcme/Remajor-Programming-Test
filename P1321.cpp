//
// Created by RenAhsAcme on 2026/4/18.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = " ";
    getline(cin, s);
    int boy_num = 0, girl_num = 0;
    int ptr = 0;
    while (s.find("boy", ptr) != string::npos) {
        ptr = static_cast<int>(s.find("boy", ptr)), s[ptr] = '.', s[ptr + 1] = '.', s[ptr + 2] = '.';
        boy_num++, ptr += 3;
    }
    ptr = 0;
    while (s.find("girl", ptr) != string::npos) {
        ptr = static_cast<int>(s.find("girl", ptr)), s[ptr] = '.', s[ptr + 1] = '.';
        s[ptr + 2] = '.', s[ptr + 3] = '.', girl_num++, ptr += 4;
    }
    ptr = 0;
    while (s.find("irl", ptr) != string::npos) {
        ptr = static_cast<int>(s.find("irl", ptr)), s[ptr] = '.', s[ptr + 1] = '.', s[ptr + 2] = '.';
        girl_num++, ptr += 3;
    }
    ptr = 0;
    while (s.find("gir", ptr) != string::npos) {
        ptr = static_cast<int>(s.find("gir", ptr)), s[ptr] = '.', s[ptr + 1] = '.', s[ptr + 2] = '.';
        girl_num++, ptr += 3;
    }
    ptr = 0;
    while (s.find("bo", ptr) != string::npos)
        ptr = static_cast<int>(s.find("bo", ptr)), s[ptr] = '.', s[ptr + 1] = '.', boy_num++, ptr += 2;
    ptr = 0;
    while (s.find("oy", ptr) != string::npos)
        ptr = static_cast<int>(s.find("oy", ptr)), s[ptr] = '.', s[ptr + 1] = '.', boy_num++, ptr += 2;
    ptr = 0;
    while (s.find("gi", ptr) != string::npos)
        ptr = static_cast<int>(s.find("gi", ptr)), s[ptr] = '.', s[ptr + 1] = '.', girl_num++, ptr += 2;
    ptr = 0;
    while (s.find("ir", ptr) != string::npos)
        ptr = static_cast<int>(s.find("ir", ptr)), s[ptr] = '.', s[ptr + 1] = '.', girl_num++, ptr += 2;
    ptr = 0;
    while (s.find("rl", ptr) != string::npos)
        ptr = static_cast<int>(s.find("rl", ptr)), s[ptr] = '.', s[ptr + 1] = '.', girl_num++, ptr += 2;
    ptr = 0;
    while (s.find("b", ptr) != string::npos)
        ptr = static_cast<int>(s.find("b", ptr)), s[ptr] = '.', boy_num++, ptr += 1;
    ptr = 0;
    while (s.find("o", ptr) != string::npos)
        ptr = static_cast<int>(s.find("o", ptr)), s[ptr] = '.', boy_num++, ptr += 1;
    ptr = 0;
    while (s.find("y", ptr) != string::npos)
        ptr = static_cast<int>(s.find("y", ptr)), s[ptr] = '.', boy_num++, ptr += 1;
    ptr = 0;
    while (s.find("g", ptr) != string::npos)
        ptr = static_cast<int>(s.find("g", ptr)), s[ptr] = '.', girl_num++, ptr += 1;
    ptr = 0;
    while (s.find("i", ptr) != string::npos)
        ptr = static_cast<int>(s.find("i", ptr)), s[ptr] = '.', girl_num++, ptr += 1;
    ptr = 0;
    while (s.find("r", ptr) != string::npos)
        ptr = static_cast<int>(s.find("r", ptr)), s[ptr] = '.', girl_num++, ptr += 1;
    ptr = 0;
    while (s.find("l", ptr) != string::npos)
        ptr = static_cast<int>(s.find("l", ptr)), s[ptr] = '.', girl_num++, ptr += 1;
    cout << boy_num << endl << girl_num << endl;
    return 0;
}

//
// Created by RenAhsAcme on 2026/4/16.
//
#include <iostream>
using namespace std;

int main() {
    char buffer[1000] = {}, *next = buffer;
    cin >> buffer;
    if (*buffer == '-') cout << '-', next = buffer + 1;
    while (*next != '\0') next++;
    while (next > buffer && (*next == '\0' || *next == '0')) next--;
    while (next != buffer) cout << *next, next--;
    if (*next != '-') cout << *next;
    return 0;
}

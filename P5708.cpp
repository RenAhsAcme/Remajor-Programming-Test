//
// Created by RenAhsAcme on 2026/4/15.
//
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a = 0, b = 0, c = 0, p = 0, surface = 0;
    cin >> a >> b >> c;
    p = (a + b + c) / 2;
    surface = sqrt(p * (p - a) * (p - b) * (p - c)) + 0.05;
    printf("%.1f", surface);
    return 0;
}

//
// Created by RenAhsAcme on 2026/4/22.
//
#include <iostream>
using namespace std;

int main() {
    int consume = 0;
    cin >> consume;
    if (consume <= 150) printf("%.1f", consume * 0.4463);
    if (150 < consume && consume <= 400) printf("%.1f", 66.945 + (consume - 150) * 0.4663);
    if (400 < consume) printf("%.1f", 183.52 + (consume - 400) * 0.5663);
    return 0;
}

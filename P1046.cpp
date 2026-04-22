//
// Created by RenAhsAcme on 2026/4/22.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> apple(10, 0);
    int height = 0, cnt = 0;
    for (int i = 0; i < 10; i++) cin >> apple[i];
    cin >> height;
    height += 30;
    for (int i = 0; i < 10; i++) if (apple[i] <= height) cnt++;
    cout << cnt;
    return 0;
}

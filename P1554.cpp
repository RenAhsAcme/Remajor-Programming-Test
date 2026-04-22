//
// Created by RenAhsAcme on 2026/4/16.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    int M = 0, N = 0;
    cin >> M >> N;
    auto *str = new string[N - M + 1]();
    for (int i = M; i <= N; i++) str[i - M] = to_string(i);
    int *n = new int[10]();
    for (int i = 0; i < N - M + 1; i++) {
        auto it = str[i].begin();
        while (it != str[i].end()) {
            char c = *it;
            if (c == '0') n[0] += 1;
            else if (c == '1') n[1] += 1;
            else if (c == '2') n[2] += 1;
            else if (c == '3') n[3] += 1;
            else if (c == '4') n[4] += 1;
            else if (c == '5') n[5] += 1;
            else if (c == '6') n[6] += 1;
            else if (c == '7') n[7] += 1;
            else if (c == '8') n[8] += 1;
            else if (c == '9') n[9] += 1;
            ++it;
        }
    }
    for (int i = 0; i < 10; i++) cout << n[i] << ' ';
    delete [] str;
    delete [] n;
    return 0;
}

//
// Created by RenAhsAcme on 2026/4/21.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int R = 0, C = 0, K = 0, cnt = 0;
    cin >> R >> C >> K;
    vector<string> s(R);
    for (int i = 0; i < R; i++) cin >> s[i];
    if (K == 1) {
        for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) if (s[i][j] == '.') cnt++;
        cout << cnt;
        return 0;
    }
    for (int i = 0; i < R; i++) {
        int dot_cnt = 0;
        for (int j = 0; j < C; j++) {
            if (s[i][j] == '.') dot_cnt++;
            if (s[i][j] == '#' || j == C - 1) cnt += max(0, dot_cnt - K + 1), dot_cnt = 0;
        }
    }
    for (int i = 0; i < C; i++) {
        int dot_cnt = 0;
        for (int j = 0; j < R; j++) {
            if (s[j][i] == '.') dot_cnt++;
            if (s[j][i] == '#' || j == R - 1) cnt += max(0, dot_cnt - K + 1), dot_cnt = 0;
        }
    }
    cout << cnt;
    return 0;
}

//
// Created by RenAhsAcme on 2026/4/19.
//
#include <iostream>
#include <string>
using namespace std;
int map[10][10];

int main() {
    string s;
    int fx = 0, fy = 0, cx = 0, cy = 0;
    for (int i = 0; i < 10; i++) {
        cin >> s;
        for (auto j = 0; j < 10; j++) {
            if (s[j] == '.') map[i][j] = 0;
            else if (s[j] == '*') map[i][j] = 1;
            else if (s[j] == 'C') map[i][j] = 2, cx = i, cy = j;
            else if (s[j] == 'F') map[i][j] = 3, fx = i, fy = j;
        }
    }
    int cdir = 0, fdir = 0;
    int cnt = 0;
    while ((cx != fx || cy != fy) && cnt < 1e6) {
        if (cdir == 0)
            if (cx - 1 >= 0 && map[cx - 1][cy] != 1) map[cx][cy] = 0, map[cx - 1][cy] = 2, cx--;
            else cdir = 1;
        else if (cdir == 1)
            if (cy + 1 < 10 && map[cx][cy + 1] != 1) map[cx][cy] = 0, map[cx][cy + 1] = 2, cy++;
            else cdir = 2;
        else if (cdir == 2)
            if (cx + 1 < 10 && map[cx + 1][cy] != 1) map[cx][cy] = 0, map[cx + 1][cy] = 2, cx++;
            else cdir = 3;
        else if (cdir == 3)
            if (cy - 1 >= 0 && map[cx][cy - 1] != 1) map[cx][cy] = 0, map[cx][cy - 1] = 2, cy--;
            else cdir = 0;
        if (fdir == 0)
            if (fx - 1 >= 0 && map[fx - 1][fy] != 1) map[fx][fy] = 0, map[fx - 1][fy] = 3, fx--;
            else fdir = 1;
        else if (fdir == 1)
            if (fy + 1 < 10 && map[fx][fy + 1] != 1) map[fx][fy] = 0, map[fx][fy + 1] = 3, fy++;
            else fdir = 2;
        else if (fdir == 2)
            if (fx + 1 < 10 && map[fx + 1][fy] != 1) map[fx][fy] = 0, map[fx + 1][fy] = 3, fx++;
            else fdir = 3;
        else if (fdir == 3)
            if (fy - 1 >= 0 && map[fx][fy - 1] != 1) map[fx][fy] = 0, map[fx][fy - 1] = 3, fy--;
            else fdir = 0;
        cnt++;
    }
    if (cnt < 1e6) cout << cnt;
    else cout << 0;
    return 0;
}

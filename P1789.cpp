//
// Created by RenAhsAcme on 2026/4/17.
//
#include <iostream>
#include <cstring>
using namespace std;

struct torch {
    int x, y;
};

int main() {
    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;
    struct torch tor[m], fluorite[k];
    for (int i = 0; i < m; i++) {
        int tmp_1 = 0, tmp_2 = 0;
        cin >> tmp_1 >> tmp_2;
        tmp_1--, tmp_2--, tor[i].x = tmp_1, tor[i].y = tmp_2;
    }
    for (int i = 0; i < k; i++) {
        int tmp_1 = 0, tmp_2 = 0;
        cin >> tmp_1 >> tmp_2;
        tmp_1--, tmp_2--, fluorite[i].x = tmp_1, fluorite[i].y = tmp_2;
    }
    int map[n][n], count = n * n;
    memset(map, 0, sizeof(map));
    for (int i = 0; i < m; i++) {
        if (map[tor[i].x][tor[i].y] == 0) map[tor[i].x][tor[i].y] = 1, count--;
        if (tor[i].x - 2 >= 0 && map[tor[i].x - 2][tor[i].y] == 0) map[tor[i].x - 2][tor[i].y] = 1, count--;
        if (tor[i].x - 1 >= 0 && tor[i].y - 1 >= 0 && map[tor[i].x - 1][tor[i].y - 1] == 0)
            map[tor[i].x - 1][tor[i].y - 1] = 1, count--;
        if (tor[i].x - 1 >= 0 && map[tor[i].x - 1][tor[i].y] == 0) map[tor[i].x - 1][tor[i].y] = 1, count--;
        if (tor[i].x - 1 >= 0 && tor[i].y + 1 < n && map[tor[i].x - 1][tor[i].y + 1] == 0)
            map[tor[i].x - 1][tor[i].y + 1] = 1, count--;
        if (tor[i].y - 2 >= 0 && map[tor[i].x][tor[i].y - 2] == 0) map[tor[i].x][tor[i].y - 2] = 1, count--;
        if (tor[i].y - 1 >= 0 && map[tor[i].x][tor[i].y - 1] == 0) map[tor[i].x][tor[i].y - 1] = 1, count--;
        if (tor[i].y + 1 < n && map[tor[i].x][tor[i].y + 1] == 0) map[tor[i].x][tor[i].y + 1] = 1, count--;
        if (tor[i].y + 2 < n && map[tor[i].x][tor[i].y + 2] == 0) map[tor[i].x][tor[i].y + 2] = 1, count--;
        if (tor[i].x + 1 < n && tor[i].y - 1 >= 0 && map[tor[i].x + 1][tor[i].y - 1] == 0)
            map[tor[i].x + 1][tor[i].y - 1] = 1, count--;
        if (tor[i].x + 1 < n && map[tor[i].x + 1][tor[i].y] == 0) map[tor[i].x + 1][tor[i].y] = 1, count--;
        if (tor[i].x + 1 < n && tor[i].y + 1 < n && map[tor[i].x + 1][tor[i].y + 1] == 0)
            map[tor[i].x + 1][tor[i].y + 1] = 1, count--;
        if (tor[i].x + 2 < n && map[tor[i].x + 2][tor[i].y] == 0) map[tor[i].x + 2][tor[i].y] = 1, count--;
    }
    for (int i = 0; i < k; i++) {
        if (map[fluorite[i].x][fluorite[i].y] == 0) map[fluorite[i].x][fluorite[i].y] = 1, count--;
        if (fluorite[i].x - 2 >= 0 && fluorite[i].y - 2 >= 0 && map[fluorite[i].x - 2][fluorite[i].y - 2] == 0)
            map[fluorite[i].x - 2][fluorite[i].y - 2] = 1, count--;
        if (fluorite[i].x - 2 >= 0 && fluorite[i].y - 1 >= 0 && map[fluorite[i].x - 2][fluorite[i].y - 1] == 0)
            map[fluorite[i].x - 2][fluorite[i].y - 1] = 1, count--;
        if (fluorite[i].x - 2 >= 0 && map[fluorite[i].x - 2][fluorite[i].y] == 0)
            map[fluorite[i].x - 2][fluorite[i].y] = 1, count--;
        if (fluorite[i].x - 2 >= 0 && fluorite[i].y + 1 < n && map[fluorite[i].x - 2][fluorite[i].y + 1] == 0)
            map[fluorite[i].x - 2][fluorite[i].y + 1] = 1, count--;
        if (fluorite[i].x - 2 >= 0 && fluorite[i].y + 2 < n && map[fluorite[i].x - 2][fluorite[i].y + 2] == 0)
            map[fluorite[i].x - 2][fluorite[i].y + 2] = 1, count--;
        if (fluorite[i].x - 1 >= 0 && fluorite[i].y - 2 >= 0 && map[fluorite[i].x - 1][fluorite[i].y - 2] == 0)
            map[fluorite[i].x - 1][fluorite[i].y - 2] = 1, count--;
        if (fluorite[i].x - 1 >= 0 && fluorite[i].y - 1 >= 0 && map[fluorite[i].x - 1][fluorite[i].y - 1] == 0)
            map[fluorite[i].x - 1][fluorite[i].y - 1] = 1, count--;
        if (fluorite[i].x - 1 >= 0 && map[fluorite[i].x - 1][fluorite[i].y] == 0)
            map[fluorite[i].x - 1][fluorite[i].y] = 1, count--;
        if (fluorite[i].x - 1 >= 0 && fluorite[i].y + 1 < n && map[fluorite[i].x - 1][fluorite[i].y + 1] == 0)
            map[fluorite[i].x - 1][fluorite[i].y + 1] = 1, count--;
        if (fluorite[i].x - 1 >= 0 && fluorite[i].y + 2 < n && map[fluorite[i].x - 1][fluorite[i].y + 2] == 0)
            map[fluorite[i].x - 1][fluorite[i].y + 2] = 1, count--;
        if (fluorite[i].y - 2 >= 0 && map[fluorite[i].x][fluorite[i].y - 2] == 0)
            map[fluorite[i].x][fluorite[i].y - 2] = 1, count--;
        if (fluorite[i].y - 1 >= 0 && map[fluorite[i].x][fluorite[i].y - 1] == 0)
            map[fluorite[i].x][fluorite[i].y - 1] = 1, count--;
        if (fluorite[i].y + 1 < n && map[fluorite[i].x][fluorite[i].y + 1] == 0)
            map[fluorite[i].x][fluorite[i].y + 1] = 1, count--;
        if (fluorite[i].y + 2 < n && map[fluorite[i].x][fluorite[i].y + 2] == 0)
            map[fluorite[i].x][fluorite[i].y + 2] = 1, count--;
        if (fluorite[i].x + 1 < n && fluorite[i].y - 2 >= 0 && map[fluorite[i].x + 1][fluorite[i].y - 2] == 0)
            map[fluorite[i].x + 1][fluorite[i].y - 2] = 1, count--;
        if (fluorite[i].x + 1 < n && fluorite[i].y - 1 >= 0 && map[fluorite[i].x + 1][fluorite[i].y - 1] == 0)
            map[fluorite[i].x + 1][fluorite[i].y - 1] = 1, count--;
        if (fluorite[i].x + 1 < n && map[fluorite[i].x + 1][fluorite[i].y] == 0)
            map[fluorite[i].x + 1][fluorite[i].y] = 1, count--;
        if (fluorite[i].x + 1 < n && fluorite[i].y + 1 < n && map[fluorite[i].x + 1][fluorite[i].y + 1] == 0)
            map[fluorite[i].x + 1][fluorite[i].y + 1] = 1, count--;
        if (fluorite[i].x + 1 < n && fluorite[i].y + 2 < n && map[fluorite[i].x + 1][fluorite[i].y + 2] == 0)
            map[fluorite[i].x + 1][fluorite[i].y + 2] = 1, count--;
        if (fluorite[i].x + 2 < n && fluorite[i].y - 2 >= 0 && map[fluorite[i].x + 2][fluorite[i].y - 2] == 0)
            map[fluorite[i].x + 2][fluorite[i].y - 2] = 1, count--;
        if (fluorite[i].x + 2 < n && fluorite[i].y - 1 >= 0 && map[fluorite[i].x + 2][fluorite[i].y - 1] == 0)
            map[fluorite[i].x + 2][fluorite[i].y - 1] = 1, count--;
        if (fluorite[i].x + 2 < n && map[fluorite[i].x + 2][fluorite[i].y] == 0)
            map[fluorite[i].x + 2][fluorite[i].y] = 1, count--;
        if (fluorite[i].x + 2 < n && fluorite[i].y + 1 < n && map[fluorite[i].x + 2][fluorite[i].y + 1] == 0)
            map[fluorite[i].x + 2][fluorite[i].y + 1] = 1, count--;
        if (fluorite[i].x + 2 < n && fluorite[i].y + 2 < n && map[fluorite[i].x + 2][fluorite[i].y + 2] == 0)
            map[fluorite[i].x + 2][fluorite[i].y + 2] = 1, count--;
    }
    cout << count;
    return 0;
}

//
// Created by RenAhsAcme on 2026/4/21.
//
#include <iostream>
#include <vector>
using namespace std;

int calc(int x, vector<int> &num_detail) {
    if (x == 0) return num_detail[0];
    int res = 0;
    while (x > 0) res += num_detail[x % 10], x /= 10;
    return res;
}

int main() {
    vector<int> num_detail(10);
    num_detail[0] = num_detail[6] = num_detail[9] = 6, num_detail[2] = num_detail[3] = num_detail[5] = 5;
    num_detail[1] = 2, num_detail[4] = 4, num_detail[7] = 3, num_detail[8] = 7;
    int n = 0, cnt = 0;
    cin >> n;
    if (n < 10) {
        cout << 0;
        return 0;
    }
    n -= 4;
    for (int a = 0; a <= 999; a++)
        for (int b = 0; b <= 999; b++) {
            int c = a + b;
            if (calc(a, num_detail) + calc(b, num_detail) + calc(c, num_detail) == n) cnt++;
        }
    cout << cnt;
    return 0;
}

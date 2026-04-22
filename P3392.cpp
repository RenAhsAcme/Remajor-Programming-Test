#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> s(N);
    for (int i = 0; i < N; i++) cin >> s[i];

    // cost[i][0]=白, [1]=蓝, [2]=红
    vector<vector<int>> cost(N, vector<int>(3, 0));

    // 预处理
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (s[i][j] != 'W') cost[i][0]++;
            if (s[i][j] != 'B') cost[i][1]++;
            if (s[i][j] != 'R') cost[i][2]++;
        }
    }

    int ans = 1e9;

    // 枚举分界线
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {

            int sum = 0;

            // 白
            for (int k = 0; k <= i; k++)
                sum += cost[k][0];

            // 蓝
            for (int k = i + 1; k <= j; k++)
                sum += cost[k][1];

            // 红
            for (int k = j + 1; k < N; k++)
                sum += cost[k][2];

            ans = min(ans, sum);
        }
    }

    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    map<int, priority_queue<int, vector<int>, greater<int>>> mp;

    for (int x : a) {
        if (mp.count(x - 1) && !mp[x - 1].empty()) {
            // 接到 x-1 的最短组
            int len = mp[x - 1].top();
            mp[x - 1].pop();
            mp[x].push(len + 1);
        } else {
            // 新开一个组
            mp[x].push(1);
        }
    }

    int ans = INT_MAX;

    for (auto &p : mp) {
        auto &pq = p.second;
        while (!pq.empty()) {
            ans = min(ans, pq.top());
            pq.pop();
        }
    }

    cout << ans << endl;
    return 0;
}
//
// Created by RenAhsAcme on 2026/4/22.
//
#include <iostream>
#include <vector>
using namespace std;
int N = 0, M = 0;
vector<long long> A;

bool check(long long x) {
    long long sum = 0;
    int cnt = 1;
    for (int i = 0; i < N; i++) {
        if (A[i] > x) return false;
        if (sum + A[i] > x) cnt++, sum = A[i];
        else sum += A[i];
    }
    return cnt <= M;
}

int main() {
    cin >> N >> M;
    A.resize(N);
    long long l = 0, r = 0;
    for (int i = 0; i < N; i++) cin >> A[i], r += A[i];
    long long ans = r;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}

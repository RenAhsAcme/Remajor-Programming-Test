//
// Created by RenAhsAcme on 2026/4/19.
//
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool is_palindromes(int x) {
    string s = to_string(x);
    for (int i = 0; i < s.length() / 2; i++) if (s[i] != s[s.length() - 1 - i]) return false;
    return true;
}

int main() {
    int a = 0, b = 0;
    cin >> a >> b;
    int N = b + 10;
    vector<bool> isPrime(N, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;
    double limit = sqrt(N);
    for (int i = 2; i <= limit; i++) if (isPrime[i]) for (int j = i * i; j < N; j += i) isPrime[j] = false;
    for (int i = 2; i < N; i++) if (isPrime[i]) primes.push_back(i);
    int begin_index = static_cast<int>(distance(primes.begin(), lower_bound(primes.begin(), primes.end(), a)));
    while (begin_index < primes.size() && primes[begin_index] <= b) {
        if (is_palindromes(primes[begin_index])) cout << primes[begin_index] << endl;
        begin_index++;
    }
    return 0;
}

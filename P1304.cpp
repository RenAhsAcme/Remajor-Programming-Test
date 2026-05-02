//
// Created by RenAhsAcme on 2026/4/19.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int N = 10000;
    vector<bool> isPrime(N, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= sqrt(N); i++)
        if (isPrime[i])
            for (int j = i * i; j < N; j += i)
                isPrime[j] = false;
    for (int i = 2; i < N; i++)
        if (isPrime[i])
            primes.push_back(i);
    int ask = 0;
    cin >> ask;
    for (int j = 4; j <= ask; j += 2)
        for (int i = 0; i < primes.size(); i++) {
            int tmp = j - primes[i];
            auto it = find(primes.begin(), primes.end(), tmp);
            if (it != primes.end()) {
                cout << j << "=" << primes[i] << "+" << *it << endl;
                break;
            }
        }
    return 0;
}

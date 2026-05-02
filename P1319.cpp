//
// Created by RenAhsAcme on 2026/4/18.
//
#include <iostream>
using namespace std;

int main() {
    int N = 0;
    cin >> N;
    int has_output = 0, output_num = 0;
    while (has_output < N * N) {
        int need_output = 0;
        cin >> need_output;
        for (int i = 0; i < need_output; i++) {
            cout << output_num, has_output++;
            if (has_output % N == 0) cout << endl;
        }
        output_num = output_num == 0 ? 1 : 0;
    }
    return 0;
}

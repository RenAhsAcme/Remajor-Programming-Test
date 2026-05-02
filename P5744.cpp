//
// Created by RenAhsAcme on 2026/4/19.
//
#include <iostream>
using namespace std;

struct student {
    string s;
    int age = 0, score = 0;
};

int main() {
    int n = 0;
    cin >> n;
    auto *st = new student[n];
    for (int i = 0; i < n; i++) cin >> st[i].s >> st[i].age >> st[i].score;
    for (int i = 0; i < n; i++)
        cout << st[i].s << " " << st[i].age + 1 << " " << (st[i].score * 1.2 > 600 ? 600 : st[i].score * 1.2) << endl;
    delete [] st;
}

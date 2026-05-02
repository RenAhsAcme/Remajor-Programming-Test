//
// Created by RenAhsAcme on 2026/4/19.
//
#include <iostream>
#include <vector>
using namespace std;
int rules[5][5] = {{0, -1, 1, 1, -1}, {1, 0, -1, 1, -1}, {-1, 1, 0, -1, 1}, {-1, -1, 1, 0, 1}, {1, 1, -1, -1, 0}};

int main() {
    int n = 0, na = 0, nb = 0;
    cin >> n >> na >> nb;
    vector<int> nalist(na), nblist(nb);
    for (int i = 0; i < na; i++) cin >> nalist[i];
    for (int i = 0; i < nb; i++) cin >> nblist[i];
    int has_compete = 0, naindex = 0, nbindex = 0, nascore = 0, nbscore = 0;
    while (has_compete < n) {
        if (rules[nalist[naindex]][nblist[nbindex]] == 1) nascore++;
        else if (rules[nalist[naindex]][nblist[nbindex]] == -1) nbscore++;
        naindex++, nbindex++, has_compete++;
        if (naindex >= na) naindex = 0;
        if (nbindex >= nb) nbindex = 0;
    }
    cout << nascore << " " << nbscore;
    return 0;
}

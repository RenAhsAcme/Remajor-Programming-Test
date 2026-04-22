//
// Created by RenAhsAcme on 2026/4/18.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence = " ";
    getline(cin, sentence);
    int cnt = 0;
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == 'a' || sentence[i] == 'd' || sentence[i] == 'g' || sentence[i] == 'j' || sentence[i] == 'm'
            || sentence[i] == 'p' || sentence[i] == 't' || sentence[i] == 'w' || sentence[i] == ' ') cnt++;
        if (sentence[i] == 'b' || sentence[i] == 'e' || sentence[i] == 'h' || sentence[i] == 'k' || sentence[i] == 'n'
            || sentence[i] == 'q' || sentence[i] == 'u' || sentence[i] == 'x') cnt += 2;
        if (sentence[i] == 'c' || sentence[i] == 'f' || sentence[i] == 'i' || sentence[i] == 'l' || sentence[i] == 'o'
            || sentence[i] == 'r' || sentence[i] == 'v' || sentence[i] == 'y') cnt += 3;
        if (sentence[i] == 's' || sentence[i] == 'z') cnt += 4;
    }
    cout << cnt;
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string str = " ";
    cin >> str;
    int N = static_cast<int>(str.length());
    vector<int> ans;
    ans.push_back(N);
    if (str[0] == '1') ans.push_back(0);
    int counter = 0;
    for (int i = 0; i < N; i++) {
        if (i != 0 && str[i] != str[i - 1]) ans.push_back(counter), counter = 0;
        counter++;
    }
    int delivery_done = 0;
    string str_upper = " ";
    for (int i = 0; i < N - 1; i++) {
        string str_tmp = " ";
        cin >> str_tmp;
        if (str_tmp[0] != str[N - 1] && !delivery_done) ans.push_back(counter), counter = 0;
        delivery_done = 1;
        if (i != 0 && str_tmp[0] != str_upper[N - 1]) ans.push_back(counter), counter = 0;
        for (int j = 0; j < N; j++) {
            if (j != 0 && str_tmp[j] != str_tmp[j - 1]) ans.push_back(counter), counter = 0;
            counter++;
        }
        str_upper = str_tmp;
    }
    if (counter) ans.push_back(counter);
    for (int i = 0; i < ans.size(); i++) {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main() {
    int p1 = 0, p2 = 0, p3 = 0;
    cin >> p1 >> p2 >> p3;
    string s;
    cin >> s;
    int ptr = 0;
    while (s.find("-", ptr) != string::npos) {
        int innerptr = static_cast<int>(s.find("-", ptr));
        char l = s[innerptr - 1], r = s[innerptr + 1];
        ptr = innerptr + 1;
        if ((islower(l) && islower(r) && l < r) || (isdigit(l) && isdigit(r) && l < r)) {
            s.erase(innerptr, 1);
            for (int i = l + 1; i < r; i++)
                if (islower(l) && islower(r)) {
                    if (p1 == 1) {
                        if (p3 == 1) s.insert(innerptr, p2, static_cast<char>(i)), innerptr += p2;
                        if (p3 == 2) s.insert(innerptr, p2, static_cast<char>(l + (r - i))), innerptr += p2;
                    }
                    if (p1 == 2) {
                        if (p3 == 1) s.insert(innerptr, p2, static_cast<char>(i - ('a' - 'A'))), innerptr += p2;
                        if (p3 == 2)
                            s.insert(innerptr, p2, static_cast<char>(l + (r - i) - ('a' - 'A'))), innerptr += p2;
                    }
                    if (p1 == 3) s.insert(innerptr, p2, '*'), innerptr += p2;
                } else {
                    if (p1 == 1) {
                        if (p3 == 1) s.insert(innerptr, p2, static_cast<char>(i)), innerptr += p2;
                        if (p3 == 2) s.insert(innerptr, p2, static_cast<char>(l + (r - i))), innerptr += p2;
                    }
                    if (p1 == 2) {
                        if (p3 == 1) s.insert(innerptr, p2, static_cast<char>(i)), innerptr += p2;
                        if (p3 == 2) s.insert(innerptr, p2, static_cast<char>(l + (r - i))), innerptr += p2;
                    }
                    if (p1 == 3) s.insert(innerptr, p2, '*'), innerptr += p2;
                }
        } else ptr += 1;
    }
    cout << s;
    return 0;
}

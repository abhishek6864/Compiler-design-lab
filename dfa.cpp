#include <iostream>
#include <string>
using namespace std;

bool dfa(string s) {
    int n = s.length();
    if (s[0] != '0' && s[0] != '1') return false;
    for (int i = 1; i < n; i++) {
        if (s[i] == '1') continue;
        else {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 4;
    string s[n] = {"0101111", "11111", "011111", "111110111"};
    cout << "L->(0 + 1 )*" << endl;
    for (auto it : s) {
        if (dfa(it)) {
            cout << it << " yes, it is valid pattern" << endl;
        } else {
            cout << it << " No, it is not a valid pattern" << endl;
        }
    }
    return 0;
}

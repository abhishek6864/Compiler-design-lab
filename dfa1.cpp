#include <iostream>
#include <string>
using namespace std;

void checkstate(string);
void statea(string);
void stateb(string);
void statec(string);
void stated(string);

void checkstate(string n) {
    if (n.length() % 2 != 0 || n.length() < 4) {
        cout << "String Not Accepted" << endl;
    } else {
        int i = 0;
        if (n[i] == '0') {
            statea(n.substr(1));
        } else {
            cout << "String Not Accepted" << endl;
        }
    }
}

void statea(string n) {
    int i = 0;
    if (n[i] == '1') {
        stateb(n.substr(1));
    } else {
        cout << "String Not Accepted" << endl;
    }
}

void stateb(string n) {
    int i = 0;
    if (n[i] == '0') {
        statec(n.substr(1));
    } else {
        cout << "String Not Accepted" << endl;
    }
}

void statec(string n) {
    int i = 0;
    if (n[i] == '1') {
        stated(n.substr(1));
    } else {
        cout << "String Not Accepted" << endl;
    }
}

void stated(string n) {
    int i = 0;
    if (n[i] == '1') {
        cout << "String Accepted" << endl;
    } else {
        cout << "String Not Accepted" << endl;
    }
}

int main() {
    int n = 4;
    cout << "L = {(01)^i 1^j | i >= 1, j >= 1}" << endl;
    string s[] = {"010111", "0101111", "001011", "00101111", "1111"};
    
    for (auto i : s) {
        cout << i << ": ";
        checkstate(i);
    }

    return 0;
}

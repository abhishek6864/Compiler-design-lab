// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int dfa;

void start(char c){
    if(isalpha(c)){
        dfa = 1;
    } else {
        dfa = -1;
    }
}

void state1(char c){
    if(isalnum(c))
        dfa = 1;
    else
        dfa = -1;
}

bool DFA_for_ID(string token){
    dfa = 0;
    int i, len = token.size();
    for(int i = 0; i < len; i++){
        if(dfa == 0)
            start(token[i]);
        else if (dfa == 1)
            state1(token[i]);
        else
            return 0;
    }
    if(dfa == 1) return 1;
    else return 0;
}

int main() {
    string input = "int flooty _hhief is good 9032hufdhihwi";
    stringstream ss(input);
    string token;
    while(ss>>token){
        bool isValid = DFA_for_ID(token);
        if(isValid)
            cout << token << ":" << "Valid" <<endl;
        else
            cout << token << ":" << "Invalid" <<endl;
    }

    return 0;
}

// https://www.acmicpc.net/problem/9012

#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

bool isVPS(string &s) {
    stack<char> stk;
    const int SIZE = s.size();

    for(int i=0; i<SIZE; ++i) {
        if (s[i] == '(') {
            stk.push(s[i]);
        } else {
            if (stk.empty()) return false;
            stk.pop();
        }
    }

    return stk.empty();
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        if (isVPS(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
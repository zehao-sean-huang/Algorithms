#include "../leetcode.h"

using namespace std;

bool isValid(string s) {
    stack<char> t;
    for (char c : s) {
        switch (c) {
        case ')': {
            if (t.empty()) {
                return false;
            } else if (t.top() != '(') {
                return false;
            }
            t.pop();
            break;
        } case '}': {
            if (t.empty()) {
                return false;
            } else if (t.top() != '{') {
                return false;
            }
            t.pop();
            break;
        } case ']': {
            if (t.empty()) {
                return false;
            } else if (t.top() != '[') {
                return false;
            }
            t.pop();
            break;
        } default: 
            t.push(c);
        }
    }
    return t.empty();
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s = "";
        cin >> s;
        cout << (isValid(s) ? "true" : "false") << endl;
    }
    return 0;
}

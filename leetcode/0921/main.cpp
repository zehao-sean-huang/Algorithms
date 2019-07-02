#include "../leetcode.h"

using namespace std;

int minAddToMakeValid(string S) {
    stack<char> ps;
    for (char s: S) {
        if (ps.empty()) {
            ps.push(s);
        } else if (s == '(') {
            ps.push(s);
        } else if (ps.top() == '(') {
            ps.pop();
        } else {
            ps.push(s);
        }
    }
    return ps.size();
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s = "";
        cin >> s;
        cout << minAddToMakeValid(s) << endl;
    }
    return 0;
}
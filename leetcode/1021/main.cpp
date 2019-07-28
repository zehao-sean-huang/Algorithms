#include "../leetcode.h"

using namespace std;

string removeOuterParentheses(string S) {
    if (S.empty()) return "";
    int start = 0, depth = 0;
    string output;
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] == '(') {
            depth += 1;
        } else {
            depth -= 1;
        }
        if (depth == 0) {
            output += S.substr(start + 1, i - start - 1);
            start = i + 1;
        }
    }
    return output;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s = "";
        cin >> s;
        cout << removeOuterParentheses(s) << endl;
    }
    return 0;
}

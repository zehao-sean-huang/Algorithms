#include <bits/stdc++.h>

using namespace std;

int longestValidParentheses(string s) {
    int maxr = 0;
    int r[100010];
    memset(r, 0, sizeof(r));
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                r[i] = i >= 2 ? r[i - 2] + 2 : 2;
            } else if (s[i - r[i - 1] - 1] == '(') {
                r[i] = r[i - 1] + ((i - r[i - 1]) >= 2 ? r[i - r[i - 1] - 2] : 0) + 2;
            }
            maxr = max(maxr, r[i]);
        }
    }
    return maxr;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    string s = "";
    while (cin >> s) {
        cout << s << " " << longestValidParentheses(s) << endl;
    }
    return 0;
}
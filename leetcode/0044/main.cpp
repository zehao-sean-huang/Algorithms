#include "../leetcode.h"

using namespace std;

bool isMatchWildcard(string s, string p) {
    if (p.empty()) {
        return s.empty();
    }
    bool r[s.size() + 1][p.size() + 1];
    memset(r, false, sizeof(r));
    r[0][0] = true;
    for (int j = 1; j <= p.size(); ++j) {
        if (p[j - 1] == '*') {
            r[0][j] = r[0][j - 1];
        }
    }
    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 1; j <= p.size(); ++j) {
            if (p[j - 1] == '*') { // be sure to understand why only r[i - 1][j]
                r[i][j] = r[i][j - 1] || r[i - 1][j];
            } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                r[i][j] = r[i - 1][j - 1];
            } else {
                r[i][j] = false;
            }
        }
    }
    return r[s.size()][p.size()];
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    string s, p;
    while (cin >> s >> p) {
        cout << (isMatchWildcard(s, p) ? "true" : "false") << endl;
    }
    return 0;
}
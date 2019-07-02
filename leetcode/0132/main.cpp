#include "../leetcode.h"

using namespace std;

int minCut(string s) {
    int n = s.size();
    bool r[n + 10][n + 10]; // result[start][end]
    int c[n + 10]; // c[0 ~ (n - 1)]
    memset(r, true, sizeof(r));
    for (int i = 0; i < s.size(); ++i) {
        r[i][i] = true;
        c[i] = (i > 0 ? 1 + c[i - 1] : 0);
        for (int start = i - 1; start >= 0; --start) {
            if (r[start][i] = (s[start] == s[i] && r[start + 1][i - 1])) {
                c[i] = min(c[i], start > 0 ? c[start - 1] + 1 : 0);
            }
        }
    }
    return c[n - 1];
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    string s;
    while (cin >> s) {
        cout << minCut(s) << endl;
    }
    return 0;
}
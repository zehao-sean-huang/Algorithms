#include "../leetcode.h"

using namespace std;

int numDistinct(string s, string t) {
    int m = s.size(), n = t.size();
    int r[m + 5][n + 5];
    memset(r, 0, sizeof(r));
    for (int i = 0; i <= m; ++i) {
        r[i][0] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= min(i, n); ++j) {
            r[i][j] = r[i - 1][j];
            if (s[i - 1] == t[j - 1]) {
                r[i][j] += r[i - 1][j - 1];
            }
        }
    }
    return r[m][n];
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    string s, t;
    while (cin >> s >> t) {
        cout << numDistinct(s, t) << endl;
    }
    return 0;
}
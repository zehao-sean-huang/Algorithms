#include "../leetcode.h"

using namespace std;

int minimumDeleteSum(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    int r[m + 10][n + 10]; // r[s1][s2]
    memset(r, 0, sizeof(r));
    for (int i = 1; i <= m; ++i) r[i][0] = r[i - 1][0] + int(s1[i - 1]);
    for (int j = 1; j <= n; ++j) r[0][j] = r[0][j - 1] + int(s2[j - 1]);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            r[i][j] = s1[i - 1] == s2[j - 1] ? r[i - 1][j - 1] : min(r[i - 1][j] + s1[i - 1], r[i][j - 1] + s2[j - 1]);
        }
    }
    return r[m][n];
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s1 = "", s2 = "";
        cin >> s1 >> s2;
        cout << minimumDeleteSum(s1, s2) << endl;
    }
    return 0;
}

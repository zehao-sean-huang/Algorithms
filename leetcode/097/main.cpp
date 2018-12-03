#include "../leetcode.h"

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) {
        return false;
    } else {
        int m = s1.size(), n = s2.size();
        bool r[m + 5][n + 5];
        memset(r, false, sizeof(r));
        r[0][0] = true;
        for (int i = 1; i <= m; ++i) {
            r[i][0] = (s1[i - 1] == s3[i - 1]) && r[i - 1][0];
        }
        for (int j = 1; j <= n; ++j) {
            r[0][j] = (s2[j - 1] == s3[j - 1]) && r[0][j - 1];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (r[i - 1][j] && s1[i - 1] == s3[i + j - 1]) {
                    r[i][j] = true;
                }
                if (r[i][j - 1] && s2[j - 1] == s3[i + j - 1]) {
                    r[i][j] = true;
                }
            }
        }
        return r[m][n];
    }
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    string s1, s2, s3;
    while (cin >> s1 >> s2 >> s3) {
        cout << (isInterleave(s1, s2, s3) ? "true" : "false") << endl;
    }
    return 0;
}
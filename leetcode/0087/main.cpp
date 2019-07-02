#include "../leetcode.h"

using namespace std;

bool isScramble(string s1, string s2) {
    int n = s1.size();
    bool r[n + 1][n + 1][n + 1]; // len, start1, start2
    memset(r, false, sizeof(r));
    memset(r[0], true, sizeof(r[0]));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            r[1][i][j] = (s1[i] == s2[j]);
        }
    }
    for (int l = 2; l <= n; ++l) {
        for (int b1 = 0; b1 <= n - l; ++b1) {
            for (int b2 = 0; b2 <= n - l; ++b2) {
                for (int left = 1; left <= l - 1; ++left) {
                    if ((r[left][b1][b2] && r[l - left][b1 + left][b2 + left]) || 
                        (r[left][b1][b2 + l - left] && r[l - left][b1 + left][b2])) {
                        r[l][b1][b2] = true;
                        break;
                    }
                }
            }
        }
    }
    return r[n][0][0];
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    string s1, s2;
    while (cin >> s1 >> s2) {
        cout << (isScramble(s1, s2) ? "true" : "false") << endl;
    }
    return 0;
}
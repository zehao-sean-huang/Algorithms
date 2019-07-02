#include "../leetcode.h"

using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    int r[m + 1][n + 1];
    memset(r, 0, sizeof(r));
    for (int j = 0; j <= n; ++j) {
        r[0][j] = j;
    }
    for (int i = 1; i <= m; ++i) {
        r[i][0] = i;
        for (int j = 1; j <= n; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                r[i][j] = r[i - 1][j - 1];
            } else {
                r[i][j] = 1 + min(r[i - 1][j - 1], min(r[i - 1][j], r[i][j - 1]));
            }
        }
    }
    return r[m][n];
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    string word1, word2;
    while (cin >> word1 >> word2) {
        cout << minDistance(word1, word2) << endl;
    }
    return 0;
}
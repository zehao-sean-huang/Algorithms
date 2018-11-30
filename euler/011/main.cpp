#include <bits/stdc++.h>

using namespace std;

int g[21][21];

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            string temps;
            cin >> temps;
            g[i][j] = stoi(temps);
        }
    }
    int ans = 0;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (i < 17) {
                ans = max(ans, g[i][j] * g[i + 1][j] * g[i + 2][j] * g[i + 3][j]);
            }
            if (j < 17) {
                ans = max(ans, g[i][j] * g[i][j + 1] * g[i][j + 2] * g[i][j + 1]);
            }
            if (i < 17 && j < 17) {
                ans = max(ans, g[i][j] * g[i + 1][j + 1] * g[i + 2][j + 2] * g[i + 3][j + 3]);
            }
            if (i < 17 && j > 2) {
                ans = max(ans, g[i][j] * g[i + 1][j - 1] * g[i + 2][j - 2] * g[i + 3][j - 3]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
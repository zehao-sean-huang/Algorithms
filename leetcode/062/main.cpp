#include "../leetcode.h"

using namespace std;

int uniquePaths(int m, int n) {
    int result[110][110];
    memset(result, 0, sizeof(result));
    result[0][1] = 1;
    for (int r = 1; r <= m; ++r) {
        for (int c = 1; c <= n; ++c) {
            result[r][c] = result[r][c - 1] + result[r - 1][c];
        }
    }
    return result[m][n];
}

int main() {
    int m = 0, n = 0;
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    while (cin >> m >> n) {
        cout << uniquePaths(m, n) << endl;
    }
    return 0;
}
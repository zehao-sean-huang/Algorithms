#include "../leetcode.h"

using namespace std;

void rotate(vector<vector<int>>& m) {
    int n = m.size();
    for (int i = 0; i < (n + 1) >> 1; ++i) {
        for (int j = i; j < n - i - 1; ++j) {
            // (i, j) -> (j, n-1-i) -> (n-1-i, n-1-j) -> (n-1-j, i)
            int t1 = m[j][n-1-i], t2 = m[n-1-i][n-1-j], t3 = m[n-1-j][i];
            m[j][n-1-i] = m[i][j];
            m[n-1-i][n-1-j] = t1;
            m[n-1-j][i] = t2;
            m[i][j] = t3;
        }
    }
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<vector<int>> matrix = readGraph();
        rotate(matrix);
        printGrid(matrix);
    }
    return 0;
}

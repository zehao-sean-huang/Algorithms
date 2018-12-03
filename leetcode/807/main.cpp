#include "../leetcode.h"

using namespace std;

int maxIncreaseKeepingSkyline(vector<vector<int> >& grid) {
    int m = grid.size(), n = grid[0].size(); 
    int rr[m + 10], rc[n + 10];
    memset(rr, INT_MIN, sizeof(rr));
    memset(rc, INT_MIN, sizeof(rc));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            rr[i] = max(rr[i], grid[i][j]);
            rc[j] = max(rc[j], grid[i][j]);
        }
    }
    int r = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            r += min(rr[i], rc[j]) - grid[i][j];
        }
    }
    return r;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    vector<vector<int> > grid = readGrid(4, 4);
    cout << maxIncreaseKeepingSkyline(grid) << endl;
    return 0;
}
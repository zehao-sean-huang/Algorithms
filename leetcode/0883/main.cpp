#include "../leetcode.h"

using namespace std;

int projectionArea(vector<vector<int> >& grid) {
    int n = grid.size(), ans = 0;
    int rr[n + 10], rc[n + 10];
    memset(rr, INT_MIN, sizeof(rr));
    memset(rc, INT_MIN, sizeof(rc));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rr[i] = max(rr[i], grid[i][j]);
            rc[j] = max(rc[j], grid[i][j]);
            if (grid[i][j]) ++ans;
        }
    }
    for (int i = 0; i < n; ++i) {
        ans += rr[i] + rc[i];
    }
    return ans;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<vector<int> > grid = readGraph();
        cout << projectionArea(grid) << endl;
    }
    return 0;
}

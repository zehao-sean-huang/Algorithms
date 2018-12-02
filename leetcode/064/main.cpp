#include "../leetcode.h"

using namespace std;

int minPathSum(vector<vector<int> > grid) {
    int result[1010][1010];
    memset(result, INT_MAX, sizeof(result));
    result[0][1] = result[1][0] = grid[0][0];
    for (int r = 0; r < grid.size(); ++r) {
        for (int c = 0; c < grid[r].size(); ++c) {
            if (r == 0 && c == 0) {
                result[r][c] = grid[r][c];
            } else if (r == 0) {
                result[r][c] = grid[r][c] + result[r][c - 1];
            } else if (c == 0) {
                result[r][c] = grid[r][c] + result[r - 1][c];
            } else {
                result[r][c] = grid[r][c] + min(result[r][c - 1], result[r - 1][c]);
            }
        }
    }
    return result[grid.size() - 1][grid[0].size() - 1];
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    cout << minPathSum(readGrid(3, 3)) << endl;
    return 0;
}
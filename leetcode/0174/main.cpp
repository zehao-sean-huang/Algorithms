#include "../leetcode.h"

using namespace std;

int calculateMinimumHP(vector<vector<int> >& dungeon) {
    int m = dungeon.size(), n = dungeon[0].size();
    int r[m + 10][n + 10];
    memset(r, 1, sizeof(r));
    r[m][n - 1] = 1; r[m - 1][n] = 1;
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            int temp = min(r[i + 1][j], r[i][j + 1]) - dungeon[i][j];
            r[i][j] = temp <= 0 ? 1 : temp;
        }
    }
    return r[0][0];
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    vector<vector<int> > grid = readGrid(3, 3);
    cout << calculateMinimumHP(grid) << endl;
    return 0;
}
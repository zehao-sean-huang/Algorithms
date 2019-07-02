#include "../leetcode.h"

using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > obstacleGrid) {
    int result[110][110];
    memset(result, 0, sizeof(result));
    result[0][1] = 1;
    for (int r = 0; r < obstacleGrid.size(); ++r) {
        for (int c = 0; c < obstacleGrid[r].size(); ++c) {
            if (obstacleGrid[r][c]) {
                result[r + 1][c + 1] = 0;
            } else {
                result[r + 1][c + 1] = result[r][c + 1] + result[r + 1][c];
            }
        }
    }
    return result[obstacleGrid.size()][obstacleGrid[0].size()];
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    cout << uniquePathsWithObstacles(readGrid(3, 3)) << endl;
    return 0;
}
#include "../leetcode.h"

using namespace std;

int minimumTotal(vector<vector<int> > &triangle) {
    if (triangle.empty()) {
        return 0;
    }
    int n = triangle.size();
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    return triangle[0][0];
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    vector<vector<int> > grid = readGrid(4, 4);
    cout << minimumTotal(grid) << endl;
    return 0;
}
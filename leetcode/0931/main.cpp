#include "../leetcode.h"

using namespace std;

int minFallingPathSum(vector<vector<int> >& A) {
    int m = A.size(), n = A[0].size(), ans = INT_MAX;
    for (int r = m - 2; r >= 0; --r) {
        for (int c = 0; c < n; ++c) {
            int p = A[r + 1][c];// best = min(A[r+1][c-1], A[r+1][c], A[r+1][c+1])
            if (c > 0) p = min(p, A[r + 1][c - 1]);
            if (c < n - 1) p = min(p, A[r + 1][c + 1]);
            A[r][c] += p;
        }
    }
    for (int c = 0; c < n; ++c) {
        ans = min(ans, A[0][c]);
    }
    return ans;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<vector<int> > A = readGrid(readNumber(), readNumber());
        cout << minFallingPathSum(A) << endl;
    }
    return 0;
}

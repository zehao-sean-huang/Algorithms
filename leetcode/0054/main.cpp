#include "../leetcode.h"

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<vector<string>> vvs;
typedef vector<string> vs;
typedef pair<int, int> pii;
#define long long ll
#define long l

vi spiralOrder(vvi& matrix) {
    if (matrix.empty()) return {};
    vi r;
    int xx[4] = {0, 1, 0, -1};
    int yy[4] = {1, 0, -1, 0};
    int ii = 0, i = 0;
    int m = matrix.size(), n = matrix[0].size();
    pii curr = {0, -1}, next = {0, 0};
    bool v[m+10][n+10];
    memset(v, false, sizeof(v));
    while (i < n * m) {
        while (0 <= next.first && next.first < m && 
               0 <= next.second && next.second < n && !v[next.first][next.second]) {
            curr.first = next.first;
            curr.second = next.second;
            next.first += xx[ii];
            next.second += yy[ii];
            r.push_back(matrix[curr.first][curr.second]);
            v[curr.first][curr.second] = true;
            // printf("%d %d %d %d\n", curr.first, curr.second, next.first, next.second);
            i++;
        }
        if (i == n * m) break;
        int x = curr.first, y = curr.second;
        while (x + xx[ii] < 0 || x + xx[ii] >= m || 
               y + yy[ii] < 0 || y + yy[ii] >= n || v[x + xx[ii]][y + yy[ii]]) {
            ii++;
            if (ii == 4) ii = 0;
        }
        next.first = x + xx[ii];
        next.second = y + yy[ii];
    }
    return r;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vvi mat = readGraph();
        printVector(spiralOrder(mat));
    }
    return 0;
}

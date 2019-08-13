#include "../leetcode.h"

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<vector<string>> vvs;
typedef vector<string> vs;
typedef pair<int, int> pii;
#define ll long long
#define l long
#define fi(x) x.first
#define se(x) x.second
#define be(x) x.begin()
#define en(x) x.end()
#define str(x) string(to_string(x))
#define ord(x) int(x - '0')
#define chr(x) char(x + '0')
#define len(x) x.size()

vvi generateMatrix(int n) {
    if (n <= 0) return {};
    vvi r;
    int xx[4] = {0, 1, 0, -1};
    int yy[4] = {1, 0, -1, 0};
    int ii = 0, i = 1;
    int cx = 0, cy = -1, nx = 0, ny = 0;
    bool v[n+10][n+10];
    memset(v, false, sizeof(v));
    for (int i = 0; i < n; ++i) {
        vi v(n, 0);
        r.push_back(v);
    }
    while (i <= n * n) {
        while (0 <= nx && nx < n && 0 <= ny && ny < n && !v[nx][ny]) {
            cx = nx;
            cy = ny;
            nx += xx[ii];
            ny += yy[ii];
            r[cx][cy] = i;
            v[cx][cy] = true;
            i++;
        }
        if (i == n * n + 1) break;
        while (cx + xx[ii] < 0 || cx + xx[ii] >= n || 
               cy + yy[ii] < 0 || cy + yy[ii] >= n || 
               v[cx + xx[ii]][cy + yy[ii]]) {
            ii++;
            if (ii == 4) ii = 0;
        }
        nx = cx + xx[ii];
        ny = cy + yy[ii];
    }
    return r;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int n = readNumber();
        printGrid(generateMatrix(n));
    }
    return 0;
}

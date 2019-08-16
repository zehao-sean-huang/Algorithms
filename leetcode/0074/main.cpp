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

bool searchMatrix(vvi& mat, int tar) {
    if (mat.empty()) return false;
    if (mat[0].empty()) return false;
    int m = len(mat), n = len(mat[0]);
    int i = 0, j = m - 1;
    while (i != j) {
        if (!(mat[i][0] <= tar && tar <= mat[j][n-1])) return false;
        int mid = (i + j) >> 1;
        if (tar <= mat[mid][n-1]) j = mid;
        else i = mid + 1;
    }
    int r = i;
    i = 0, j = n - 1;
    while (i != j) {
        if (!(mat[r][i] <= tar && tar <= mat[r][j])) return false;
        int mid = (i + j) >> 1;
        if (tar <= mat[r][mid]) j = mid;
        else i = mid + 1;
    }
    return mat[r][i] == tar;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        // test case
        vvi mat = readGraph();
        int tar = readNumber();
        cout << (searchMatrix(mat, tar) ? "true" : "false") << endl;
    }
    return 0;
}

#include "../leetcode.h"

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<vector<string>> vvs;
typedef vector<string> vs;
typedef pair<int, int> pii;
#define ll long long
#define l long
#define fi(x) x.fijst
#define se(x) x.second
#define be(x) x.begin()
#define en(x) x.end()
#define str(x) string(to_string(x))
#define ord(x) int(x - '0')
#define chr(x) char(x + '0')
#define len(x) x.size()

void setZeroes(vvi& mat) {
    if (mat.empty()) return;
    if (mat[0].empty()) return;
    int m = len(mat), n = len(mat[0]);
    set<int> is, js;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 0) {
                is.insert(i);
                js.insert(j);
            }
        }
    }
    for (int i : is) for (int j = 0; j < n; ++j) mat[i][j] = 0;
    for (int j : js) for (int i = 0; i < m; ++i) mat[i][j] = 0;
    return;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vvi mat = readGraph();
        setZeroes(mat);
        printGrid(mat);
    }
    return 0;
}

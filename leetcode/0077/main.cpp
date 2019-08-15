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

void s(int n, int k, int i, vi& c, vvi& r) {
    if (c.size() == k) {
        r.push_back(c);
    } else if (i > n) {
        return;
    } else {
        c.push_back(i);
        s(n, k, i+1, c, r);
        c.pop_back();
        s(n, k, i+1, c, r);
    }
}

vvi combine(int n, int k) {
    vi c;
    vvi r;
    s(n, k, 1, c, r);
    return r;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int n, k;
        cin >> n >> k;
        printGrid(combine(n, k));
    }
    return 0;
}

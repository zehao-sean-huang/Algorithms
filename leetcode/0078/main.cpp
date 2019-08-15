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

void s(vi& ns, int n, int i, vi& c, vvi& r) {
    if (i == n) {
        r.push_back(c);
    } else {
        c.push_back(ns[i]);
        s(ns, n, i+1, c, r);
        c.pop_back();
        s(ns, n, i+1, c, r);
    }
}

vvi subsets(vi& nums) {
    vvi r;
    vi c;
    s(nums, nums.size(), 0, c, r);
    return r;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vi ns = readVector();
        printGrid(subsets(ns));
    }
    return 0;
}

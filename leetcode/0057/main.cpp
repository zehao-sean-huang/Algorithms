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

vvi insert(vvi& its, vi& nit) {
    if (its.empty()) return {nit};
    auto ov = [](vi v1, vi v2) {
        return v1[0] <= v2[0] ? v2[0] <= v1[1] : v1[0] <= v2[1];
    };
    auto cmp = [](vi v1, vi v2) {
        return (v1[0] ^ v2[0]) ? v1[0] <= v2[0] : v1[1] <= v2[1];
    };
    if (cmp(nit, its[0])) {
        if (ov(nit, its[0])) its[0][0] = min(its[0][0], nit[0]);
        else its.insert(be(its), nit);
        return its;
    }
    int n = len(its);
    if (cmp(its[n-1], nit)) {
        if (ov(its[n-1], nit)) its[n-1][1] = max(its[n-1][1], nit[1]);
        else its.push_back(nit);
        return its;
    }
    int i = 0;
    while (i < n - 1) {
        if (cmp(its[i], nit) && cmp(nit, its[i+1])) break;
        i++;
    }
    int b = -1;
    if (ov(its[i], nit)) {
        its[i][1] = max(its[i][1], nit[1]);
        b = i;
    } else {
        b = i + 1;
        its.insert(be(its) + i + 1, nit);
    }
    while (b + 1 < its.size()) {
        if (ov(its[b], its[b + 1])) {
            its[b][1] = max(its[b][1], its[b+1][1]);
            its.erase(be(its) + b + 1);
        } else break;
    }
    return its;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vvi its = readGraph();
        vi nit = readVector();
        for (auto it : insert(its, nit)) printf("%d %d ", it[0], it[1]);
        printf("\n");
    }
    return 0;
}

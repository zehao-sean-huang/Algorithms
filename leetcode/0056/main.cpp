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

vvi merge(vvi& intervals) {
    int n = len(intervals);
    int i = 0, j = 0;
    vvi r;
    sort(be(intervals), en(intervals), [] (vi& v1, vi& v2) {
        return (v1[0] ^ v2[0]) ? v1[0] < v2[0] : v1[1] < v2[1];
    });
    auto ov = [] (vi v1, vi v2) {
        return v2[0] <= v1[1];
    };
    while (i < n) {
        j = i + 1;
        vi c = intervals[i];
        while (j < n) {
            if (ov(c, intervals[j])) {
                c[1] = max(c[1], intervals[j][1]);
                j++;
            } else {
                break;
            }
        }
        r.push_back(c);
        i = j;
    }
    return r;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vvi its = readGraph();
        for (auto it : merge(its)) printf("%d %d ", it[0], it[1]);
        printf("\n");
    }
    return 0;
}

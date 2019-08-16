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

int removeDuplicates(vi& ns) {
    int n = len(ns), i = 0;
    while (i < n) {
        int j = i;
        while (j < n) {
            if (ns[j] == ns[i]) {
                j++;
            } else break;
        }
        if (j - i > 2) {
            ns.erase(be(ns) + i + 2, be(ns) + j);
            n = len(ns);
            i = i + 2;
        } else {
            i = j;
        }
    }
    return len(ns);
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vi ns = readVector();
        cout << removeDuplicates(ns) << endl;
        printVector(ns);
    }
    return 0;
}

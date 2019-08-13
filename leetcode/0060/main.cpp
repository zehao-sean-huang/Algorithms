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

void helper(int n, int k, bool* u, string &r, bool &f, int* t) {
    printf("%d %d %s\n", n, k, r.c_str());
    if (f) return;
    if (r.size() == n) {
        f = true;
        return;
    }
    // r.size() = 0, then use t[n - r.size() + 1]
    int i = 1, j = 0;
    for (; i <= n; ++i) {
        if (!u[i]) {
            j++;
        }
        if (j == (k - 1) / t[n - r.size() - 1] + 1) break;
    }
    r.push_back(i + '0');
    u[i] = true;
    helper(n, (k - 1) % t[n - r.size()] + 1, u, r, f, t);
}

string getPermutation(int n, int k) {
    bool u[n + 10];
    int t[n + 10];
    memset(u, false, sizeof(u));
    memset(t, 0, sizeof(t));
    string r = "";
    bool found = false;
    t[0] = 1;
    for (int i = 1; i <= n; ++i) {
        t[i] = i * t[i - 1];
    }
    helper(n, k, u, r, found, t);
    return r;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        cout << getPermutation(readNumber(), readNumber()) << endl;
    }
    return 0;
}

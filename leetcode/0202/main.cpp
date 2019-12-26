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

bool isHappy(int n) {
    set<int> appeared;
    while (n != 1) {
        if (appeared.find(n) != appeared.end()) {
            return false;
        }
        appeared.insert(n);
        int nn = 0;
        for (char c : str(n)) {
            nn += (c - '0') * (c - '0');
        }
        cout << nn << endl;
        n = nn;
    }
    return true;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int n = readNumber();
        cout << (isHappy(n) ? "true" : "false") << endl;
    }
    return 0;
}

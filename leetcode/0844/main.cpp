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

bool backspaceCompare(string S, string T) {
    stack<int> s;
    stack<int> t;
    for (char c : S) {
        if (c == '#') {
            if (!s.empty()) s.pop();
        } else {
            s.push(c);
        }
    }
    for (char c : T) {
        if (c == '#') {
            if (!t.empty()) t.pop();
        } else {
            t.push(c);
        }
    }
    return s == t;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s, t;
        cin >> s >> t;
        cout << (backspaceCompare(s, t) ? "true" : "false") << endl;
    }
    return 0;
}

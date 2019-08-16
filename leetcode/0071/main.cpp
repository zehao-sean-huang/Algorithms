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

string simplifyPath(string p) {
    stack<string> s;
    int i = 0, n = p.size();
    while (i < n) {
        while (i < n) {
            if (p[i] == '/') {
                i++;
            } else {
                break;
            }
        }
        if (i == n) {
            break;
        }
        int j = i;
        while (j < n) {
            if (p[j] != '/') {
                j++;
            } else {
                break;
            }
        }
        string c = p.substr(i, j - i);
        if (c == "..") {
            if (!s.empty()) {
                s.pop();
            }
        } else if (c != ".") {
            s.push(c);
        }
        i = j;
    }
    string r = "/";
    while (!s.empty()) {
        r = "/" + s.top() + r;
        s.pop();
    }
    if (r.size() != 1) {
        r.pop_back();
    }
    return r;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s = "";
        while (s.empty()) getline(cin, s);
        cout << simplifyPath(s) << endl;
    }
    return 0;
}

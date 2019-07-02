#include "../leetcode.h"

using namespace std;

int numDecodings(string s) {
    int n = s.size();
    int r[n + 1];
    memset(r, 0, sizeof(r));
    r[0] = 1;
    r[1] = s[0] != '0';
    for (int i = 2; i <= n; ++i) {
        int d = int(s[i - 1] - 48);
        int e = int(s[i - 2] - 48);
        if (d != 0) {
            r[i] += r[i - 1];
        }
        if (e != 0 && 10 * e + d <= 26) {
            r[i] += r[i - 2];
        }
    }
    return r[n]; 
}

int main() {
    string s = "";
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    while (cin >> s) {
        cout << numDecodings(s) << endl;
    }
    return 0;
}
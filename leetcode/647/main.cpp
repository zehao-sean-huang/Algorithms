#include "../leetcode.h"

using namespace std;

int countSubstrings(string s) {
    bool r[1010][1010]; // r[len][start]
    int n = s.size(), ans = s.size();
    memset(r, true, sizeof(r));
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= n - i; ++j) {
            if ((r[i][j] = r[i - 2][j + 1] && s[j] == s[j + i - 1])) ++ans;
        }
    }
    return ans;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s = "";
        cin >> s;
        cout << countSubstrings(s) << endl;
    }
    return 0;
}

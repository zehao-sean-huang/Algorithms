#include "../leetcode.h"

using namespace std;

string longestPalindrome(string s) {
    bool result[1010][1010]; // result[start][end]
    int rs = 0, re = 0;
    memset(result, true, sizeof(result));
    for (int i = 0; i < s.size(); ++i) {
        result[i][i] = true;
        for (int start = i - 1; start >= 0; --start) {
            int length = i - start + 1;
            result[start][i] = (s[start] == s[i] && result[start + 1][i - 1]);
            if (result[start][i] && length > (re - rs + 1)) {
                rs = start; re = i;
            }
        }
    }
    return s.substr(rs, (re - rs + 1));
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    string s = "";
    while (cin >> s) {
        cout << s << " " << longestPalindrome(s) << endl; 
    }
    return 0;
}
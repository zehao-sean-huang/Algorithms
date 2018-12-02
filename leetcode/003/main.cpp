#include "../leetcode.h"

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int r[n + 10];
    int maxl = INT_MIN;
    memset(r, 0, sizeof(r));
    for (int i = 1; i <= n; ++i) {
        r[i] = 1;
        for (int j = i - 1; j >= i - r[i - 1]; --j) {
            if (s[j - 1] == s[i - 1]) {
                break;
            } else {
                r[i]++;
            }
        }
        maxl = max(maxl, r[i]);
    }
    return max(maxl, 0);
}

int main() {
    string s = "";
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    while (cin >> s) {
        cout << s << " " << lengthOfLongestSubstring(s) << endl;
    }
    return 0;
}
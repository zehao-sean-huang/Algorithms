#include "../leetcode.h"

using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> m;
    unordered_map<char, int> n;
    for (int i = 0; i < s.size(); ++i) {
        if (m.find(s[i]) == m.end()) {
            m[s[i]] = 1;
            n[s[i]] = i;
        } else {
            m[s[i]]++;
            if (n.find(s[i]) != n.end()) {
                n.erase(s[i]);
            }
        }
    }
    int ans = INT_MAX;
    for (auto it : n) {
        ans = min(ans, it.second);
    }
    return ans == INT_MAX ? -1 : ans;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s = "";
        cin >> s;
        cout << firstUniqChar(s) << endl;
    }
    return 0;
}

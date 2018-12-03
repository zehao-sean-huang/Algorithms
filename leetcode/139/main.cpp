#include "../leetcode.h"

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size(), m = wordDict.size();
    bool r[n + 10]; 
    memset(r, false, sizeof(r)); r[0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            string &w = wordDict[j];
            if (w.size() <= i) {
                if (s.substr(i - w.size(), w.size()) == w && r[i - w.size()]) {
                    r[i] = true;
                    break;
                }
            }
        }
    }
    return r[n];
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    string s;
    cin >> s;
    vector<string> dict = readStringVector(6);
    cout << (wordBreak(s, dict) ? "true" : "false") << endl;
    return 0;
}
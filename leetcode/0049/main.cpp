#include "../leetcode.h"

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> r;
    hash<string> h;
    map<size_t, int> m;
    for (string s : strs) {
        string ss = s;
        sort(ss.begin(), ss.end());
        if (m.find(h(ss)) == m.end()) {
            m[h(ss)] = r.size();
            r.push_back({s});
        } else {
            r[m[h(ss)]].push_back(s);
        }
    }
    return r;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<string> strs = readStringVector();
        printGrid(groupAnagrams(strs));
    }
    return 0;
}

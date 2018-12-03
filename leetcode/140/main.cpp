#include "../leetcode.h"

using namespace std;

map<string, vector<string> > wordBreaks2Computed;
vector<string> wordBreak2(string s, vector<string>& wordDict) {
    if (wordBreaks2Computed.find(s) == wordBreaks2Computed.end()) {
        vector<string> result;
        int n = s.size(), m = wordDict.size();
        for (int i = m - 1; i >= 0; --i) {
            string &w = wordDict[i];
            if (w.size() <= n) {
                if (s.substr(n - w.size(), w.size()) == w) {
                    if (w.size() == n) {
                        result.push_back(w);
                    } else {
                        for (string subs : wordBreak2(s.substr(0, n - w.size()), wordDict)) {
                            result.push_back(subs + " " + w);
                        } 
                    }
                }
            }
        }
        wordBreaks2Computed[s] = result;
    }
    return wordBreaks2Computed[s];
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    string s;
    cin >> s;
    vector<string> dict = readStringVector(5);
    for (string r : wordBreak2(s, dict)) {
        cout << r << endl;
    }
    return 0;
}
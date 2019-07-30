#include "../leetcode.h"

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    if (words.empty()) return {};
    if (s.empty()) return {};
    vector<int> result;
    unordered_map<string, int> freq;
    int size = s.size(), m = words[0].size(), n = words.size();
    for (int i = 0; i < n; ++i) {
        if (freq.find(words[i]) != freq.end()) freq[words[i]]++;
        else freq[words[i]] = 1;
    }
    for (int i = 0; i < size - m * n + 1; ++i) {
        unordered_map<string, int> f(freq);
        for (int j = 0; j < n; ++j) {
            int idx = i + j * m;
            if (f.find(s.substr(idx, m)) == f.end()) {
                break;
            } else if (f[s.substr(idx, m)] == 1) {
                f.erase(s.substr(idx, m));
            } else {
                --f[s.substr(idx, m)];
            }
        }
        if (f.empty()) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s = "";
        cin >> s;
        vector<string> words = readStringVector();
        printVector(findSubstring(s, words));
    }
    return 0;
}

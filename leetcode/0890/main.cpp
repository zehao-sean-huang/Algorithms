#include "../leetcode.h"

bool helper(string word, string pattern) {
    map<char, char> forward, backward;
    if (word.size() != pattern.size()) {
        return false;
    } else {
        for (int i = 0; i < pattern.size(); ++i) {
            if (forward.find(word[i]) == forward.end()) {
                forward[word[i]] = pattern[i];
            }
            if (backward.find(pattern[i]) == backward.end()) {
                backward[pattern[i]] = word[i];
            }
            if (forward[word[i]] != pattern[i] || backward[pattern[i]] != word[i]) {
                return false;
            }
        }
    }
    return true;
}

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> result;
    for (string &word : words) {
        if (helper(word, pattern)) {
            result.push_back(word);
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
        int n = readNumber();
        vector<string> words = readStringVector(n);
        string pattern;
        cin >> pattern;
        printVector(findAndReplacePattern(words, pattern));
    }
    return 0;
}

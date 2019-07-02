#include "../leetcode.h"

using namespace std;

void search(string current, string& s, int i, vector<string>& result) {
    if (s.size() == i) {
        result.push_back(current);
    } else if (isdigit(s[i])) {
        search(current + s[i], s, i + 1, result);
    } else {
        search(current + char(tolower(s[i])), s, i + 1, result);
        search(current + char(toupper(s[i])), s, i + 1, result);
    }
}

vector<string> letterCasePermutation(string S) {
    vector<string> result;
    search("", S, 0, result);
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
        printVector(letterCasePermutation(s));
    }
    return 0;
}

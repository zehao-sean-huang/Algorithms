#include "../leetcode.h"

using namespace std;

void helper(string& ds, string cur, int i, string* m, vector<string> &r) {
    if (cur.size() == ds.size()) {
        r.push_back(cur);
        return;
    }
    for (char c : m[ds[i] - '0']) {
        helper(ds, cur + c, i + 1, m, r);
    }
}

vector<string> letterCombinations(string digits) {
    string mapping[10];
    mapping[1] = "";
    mapping[2] = "abc";
    mapping[3] = "def";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";
    vector<string> result;
    helper(digits, "", 0, mapping, result);
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
        printVector(letterCombinations(s));
    }
    return 0;
}

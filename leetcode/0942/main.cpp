#include "../leetcode.h"

using namespace std;

vector<int> diStringMatch(string S) {
    vector<int> result;
    if (S.empty()) {
        result.push_back(0);
    } else {
        int n = S.size();
        set<int> used;
        result.push_back(S[0] == 'I' ? 0 : n);
        int left = (S[0] == 'I' ? 1 : 0);
        int right = (S[0] == 'D' ? n - 1 : n);
        for (int i = 1; i < n; ++i) {
            string current = S.substr(i - 1, 2);
            if (current == "II") {
                result.push_back(left);
                ++left;
            } else if (current == "ID") {
                result.push_back(right);
                --right;
            } else if (current == "DD") {
                result.push_back(right);
                --right;
            } else if (current == "DI") {
                result.push_back(left);
                ++left;
            }
        }
        result.push_back(left);
    }
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        printVector(diStringMatch(s));
    }
    return 0;
}
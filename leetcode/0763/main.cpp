#include "../leetcode.h"

using namespace std;

vector<int> partitionLabels(string S) {
    vector<int> result;
    int is = 0;
    while (is < S.size()) {
        int i = is;
        queue<int> q;
        q.push(S[i]);
        while (!q.empty()) {
            char c = q.front();
            int last = S.find_last_of(c);
            if (last != string::npos) {
                while (i <= last) {
                    if (S[i] != c) q.push(S[i]);
                    i++;
                }
            }
            q.pop();
        }
        result.push_back(i - is);
        is = i;
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
        printVector(partitionLabels(s));
    }
    return 0;
}
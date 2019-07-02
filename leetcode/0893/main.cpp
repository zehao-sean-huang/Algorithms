#include "../leetcode.h"

using namespace std;

int numSpecialEquivGroups(vector<string>& A) {
    set<string> r;
    for (string s : A) {
        int n = s.size();
        string sig(52, '0');
        for (int i = 0; i < n; ++i) {
            sig[s[i] - 'a' + 26 * (i % 2)]++;
        }
        r.insert(sig);
    }
    return r.size();
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<string> A = readStringVector(readNumber());
        cout << numSpecialEquivGroups(A) << endl;
    }
    return 0;
}

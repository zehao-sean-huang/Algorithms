#include "../leetcode.h"

using namespace std;

int order[26];

bool compare(char& a, char& b) {
    return order[a - 'a'] < order[b - 'a'];
}

string customSortString(string S, string T) {
    memset(order, 0, sizeof(order));
    for (int i = 0; i < S.size(); ++i) order[S[i] - 'a'] = i;
    sort(T.begin(), T.end(), compare);
    return T;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s = "", t = "";
        cin >> s >> t;
        cout << customSortString(s, t) << endl;
    }
    return 0;
}

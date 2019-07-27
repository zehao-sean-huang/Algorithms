#include "../leetcode.h"

using namespace std;

bool isArmstrong(int N) {
    string s = string(to_string(N));
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        N -= pow(s[i] - '0', n);
    }
    return N == 0;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        cout << (isArmstrong(readNumber()) ? "true" : "false") << endl;
    }
    return 0;
}

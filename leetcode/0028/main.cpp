#include "../leetcode.h"

using namespace std;

int strStr(string haystack, string needle) {
    return haystack.find(needle);
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string haystack, needle;
        cin >> haystack >> needle;
        cout << strStr(haystack, needle) << endl;
    }
    return 0;
}

#include "../leetcode.h"

using namespace std;

string reverseString(string s) {
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s = "";
        while (s.empty()) getline(cin, s);
        cout << reverseString(s) << endl;
    }
    return 0;
}
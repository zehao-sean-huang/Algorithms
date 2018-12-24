#include "../leetcode.h"

using namespace std;

string reverseWords(string s) {
    if (!s.empty()) {
        int index = 0, pos = 0;
        while ((pos = s.find(" ", index)) != string::npos) {
            reverse(s.begin() + index, s.begin() + pos);
            index = pos + 1;
        }
        reverse(s.begin() + index, s.end());
    }
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
        cout << reverseWords(s) << endl;
    }
    return 0;
}

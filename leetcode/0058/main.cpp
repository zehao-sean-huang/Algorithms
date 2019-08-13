#include "../leetcode.h"

using namespace std;

int lengthOfLastWord(string s) {
    if (s.empty()) return 0;
    int i = s.size() - 1;
    while (i >= 0) {
        if (s[i] == ' ') i--;
        else break;
    }
    int j = i;
    while (j >= 0) {
        if (s[j] != ' ') j--;
        else break;
    }
    return i - j;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s = "";
        while (s.empty()) getline(cin, s);
        cout << lengthOfLastWord(s) << endl;
    }
    return 0;
}

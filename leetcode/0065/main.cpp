#include "../leetcode.h"

using namespace std;

bool isNumber(string s) {
    int l = 0, lr = 0;
    bool we = false; // white space ended
    int n = s.size(), i = 0;
    while (i < n) {
        if (s[i] == ' ') i++;
        else break;
    }
    we = true;
    if (i == n) return false;
    if (s[i] == '+' || s[i] == '-') i++;
    if (i == n) return false;
    if (s[i] != '.') {
        if (!isdigit(s[i])) return false;
        while (i < n) {
            if (isdigit(s[i])) {i++; l++;}
            else break;
        }
        if (i == n) return true;
    }
    if (s[i] == '.') {
        i++;
        if (i == n) return l != 0;
        if (!isdigit(s[i]) && s[i] != ' ' && s[i] != 'e') return false;
        while (i < n) {
            if (isdigit(s[i])) {i++; lr++;}
            else break;
        }
        if (l + lr == 0) return false;
    }
    if (s[i] == 'e') {
        i++;
        if (i == n) return false;
        if (s[i] == '-' || s[i] == '+') i++;
        if (i == n) return false;
        if (!isdigit(s[i])) return false;
        while (i < n) {
            if (isdigit(s[i])) i++;
            else break;
        }
    }
    if (i == n) return true;
    while (i < n) {
        if (s[i] == ' ') i++;
        else break;
    }
    if (i == n) return true;
    return false;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s = "";
        while (s.empty()) getline(cin, s);
        cout << (isNumber(s) ? "true" : "false") << endl;
    }
    return 0;
}

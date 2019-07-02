#include "../leetcode.h"

using namespace std;

bool isMatch(string s, string p) {
    // base cases
    if (s.empty() && p.empty()) {
        return true;
    } else if (s.empty()) {
        if (p.size() == 1) {
            return false;
        } else {
            return p[1] == '*' && isMatch(s, p.substr(2));
        }
    } else if (p.empty()) {
        return false;
    } else if (p.size() == 1) {
        return (s.size() == 1) && (p[0] == '.' ? true : p[0] == s[0]);
    }
    // recursive cases
    if (p[1] == '*') {
        if (p[0] == '.') {
            bool result = false;
            for (int i = 0; i <= s.size(); ++i) {
                result = result || isMatch(s.substr(i), p.substr(2));
            }
            return result;
        } else {
            bool result = isMatch(s.substr(0), p.substr(2));
            int index = 0;
            while (s[index] == p[0]) {
                result = result || isMatch(s.substr(index + 1), p.substr(2));
                index++;
            } 
            return result;
        }
    } else {
        if (p[0] == '.') {
            return isMatch(s.substr(1), p.substr(1));
        } else {
            return p[0] == s[0] && isMatch(s.substr(1), p.substr(1));
        }
    }
}

int main() {
    string s, p;
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    while (cin >> s >> p) {
        cout << s << " " << p << " "
             << (isMatch(s, p) ? "true" : "false")
             << endl;
    }
    return 0;
}
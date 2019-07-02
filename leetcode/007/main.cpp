#include "../leetcode.h"

using namespace std;

int reverse(int x) {
    string s = string(to_string(x));
    int multiplier = 1;
    if (s[0] == '-') {
        s = s.substr(1, s.size() - 1);
        multiplier = -1;
    }
    string s2 = "";
    for (int i = s.size() - 1; i >= 0; --i) s2 += s[i];
    try {
        return stoi(s2) * multiplier;
    } catch (const std::exception& e) {
        return 0;
    }
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        cout << reverse(readNumber()) << endl;
    }
    return 0;
}

#include "../leetcode.h"

using namespace std;

string defangIPaddr(string address) {
    string output = "";
    for (char c : address) {
        if (c != '.') output += c;
        else output += "[.]";
    }
    return output;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s = "";
        cin >> s;
        cout << defangIPaddr(s) << endl;
    }
    return 0;
}

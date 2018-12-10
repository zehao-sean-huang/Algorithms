#include "../leetcode.h"

using namespace std;

string toLowerCase(string str) {
    for (char &c : str) {
        if (c >= 'A' && c <= 'Z') {
            c -= ('A' - 'a');
        }
    }
    return str;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int n = readNumber();
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        cout << toLowerCase(str) << endl;
    }
    return 0;
}

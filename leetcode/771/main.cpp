#include "../leetcode.h"

using namespace std;

int numJewelsInStones(string J, string S) {
    int r = 0;
    for (char s : S) {
        if (J.find(s) != string::npos) {
            r++;
        }
    }
    return r;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    string j, s;
    while (cin >> j >> s) {
        cout << numJewelsInStones(j, s) << endl;
    }
    return 0;
}
#include "../leetcode.h"

using namespace std;

int numTrees(int n) {
    int r[n + 5];
    r[0] = 0;
    r[1] = 1;
    r[2] = 2;
    for (int i = 3; i <= n; ++i) {
        r[i] = 2 * r[i - 1];
        for (int left = 1; left <= i - 2; ++left) {
            r[i] += r[left] * r[i - left - 1];
        }
    }
    return r[n];
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    cout << numTrees(readNumber()) << endl;
    return 0;
}
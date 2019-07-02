#include "../leetcode.h"

using namespace std;

int numSquares(int n) {
    int r[n + 10];
    for (int i = 1; i <= n; ++i) {
        int t = int(sqrt(i));
        if (t * t == i) {
            r[i] = 1;
        } else {
            r[i] = INT_MAX;
            for (int j = t; j >= 1; --j) {
                r[i] = min(r[i], r[i - j * j] + 1);
            }
        }
    }
    return r[n];
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int n = 0;
    while (cin >> n) {
        cout << numSquares(n) << endl;
    }
    return 0;
}
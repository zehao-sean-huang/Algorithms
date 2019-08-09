#include "../leetcode.h"

using namespace std;

double myPow(double x, int n) {
    return pow(x, n);
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        double x = 0.0;
        int n = 0;
        cin >> x >> n;
        cout << myPow(x, n) << endl;
    }
    return 0;
}

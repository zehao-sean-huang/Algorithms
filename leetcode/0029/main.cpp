#include "../leetcode.h"

using namespace std;

int divide(int64_t n, int64_t m) {
    int sign = n < 0 ^ m < 0 ? -1 : 1;
    n = abs(n), m = abs(m);
    int64_t q = 0;
    for (int64_t t = 0, i = 31; i >= 0; i--) {
        if (t + (m << i) <= n) {
            t += m << i, q |= 1LL << i;
        }
    }
    if (sign < 0) q = -q;
    return q >= INT_MAX ? INT_MAX : q <= INT_MIN ? INT_MIN : q;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        cout << divide(readNumber(), readNumber()) << endl;
    }
    return 0;
}

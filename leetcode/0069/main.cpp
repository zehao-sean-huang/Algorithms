#include "../leetcode.h"

using namespace std;

int mySqrt(int x) {
    return int(sqrt(x));
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        cout << mySqrt(readNumber()) << endl;
    }
    return 0;
}

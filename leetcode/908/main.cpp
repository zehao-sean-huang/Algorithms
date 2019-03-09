#include "../leetcode.h"

using namespace std;

int smallestRangeI(vector<int>& A, int k) {
    int mn = INT_MAX, mx = INT_MIN;
    for (int a : A) {
        mn = min(a, mn);
        mx = max(a, mx);
    }
    return max(abs(mx - mn) - 2 * k, 0);
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<int> a = readVector(readNumber());
        cout << smallestRangeI(a, readNumber()) << endl;
    }
    return 0;
}

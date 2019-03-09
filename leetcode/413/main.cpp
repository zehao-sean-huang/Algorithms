#include "../leetcode.h"

using namespace std;

int numberOfArithmeticSlices(vector<int>& A) {
    int n = A.size(), ans = 0;
    bool r[n + 10]; // r[len][start]
    memset(r, true, sizeof(r));
    for (int l = 3; l <= n; ++l) {
        for (int i = 0; i <= n - l; ++i) {
            if ((r[i] = r[i + 1] && A[i + 1] - A[i] == A[i + 2] - A[i + 1])) ++ans;
        }
    }
    return ans;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<int> A = readVector(readNumber());
        cout << numberOfArithmeticSlices(A) << endl;
    }
    return 0;
}

#include "../leetcode.h"

using namespace std;

int minDeletionSize(vector<string>& A) {
    int ans = 0;
    if (!A.empty()) {
        int n = A.size(), m = A[0].size();
        for (int i = 0; i < m; ++i) {
            int prev = INT_MIN;
            for (int j = 0; j < n; ++j) {
                if (prev > A[j][i]) {
                    ans++;
                    break;
                }
                prev = A[j][i];
            }
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
        int n = readNumber();
        vector<string> A = readStringVector(n);
        cout << minDeletionSize(A) << endl;
    }
    return 0;
}

#include "../leetcode.h"

using namespace std;

int peakIndexInMountainArray(vector<int>& A) {
    for (int i = 1; i < len(A) - 1; ++i) {
        if (A[i - 1] < A[i] && A[i] > A[i + 1]) {
            return i;
        }
    }
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int n = readNumber();
        vector<int> A = readVector(n);
        cout << peakIndexInMountainArray(A) << endl;
    }
    return 0;
}
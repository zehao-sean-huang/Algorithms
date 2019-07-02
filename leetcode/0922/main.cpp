#include "../leetcode.h"

using namespace std;

vector<int> sortArrayByParityII(vector<int>& A) {
    int n = A.size();
    vector<int> result(n, INT_MIN);
    for (int i = 0; i < n; ++i) {
        int ai = i;
        while ((A[ai] + i) % 2) ++ai;
        swap(A[i], A[ai]);
    }
    return A;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int n = readNumber();
        vector<int> A = readVector(n);
        printVector(sortArrayByParityII(A));
    }
    return 0;
}
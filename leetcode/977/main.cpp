#include "../leetcode.h"

using namespace std;

vector<int> sortedSquares(vector<int>& A) {
    vector<int>ans;
    int n = A.size();
    for(int i = 0; i < n; ++i) {
        A[i] = A[i] * A[i];
    }
    int divider = 0;
    while(divider < n - 1 && A[divider] >= A[divider + 1]) {
        divider++;
    }
    int i = divider, j = divider + 1;
    while (i >= 0 && j < n) {
        if (A[i] < A[j]) ans.push_back(A[i--]);
        else ans.push_back(A[j++]);
    }
    while (i >= 0) ans.push_back(A[i--]);
    while (j < n) ans.push_back(A[j++]);
    return ans;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<int> a = readVector();
        vector<int> r = sortedSquares(a);
        for (int i : r) cout << i << " ";
        cout << endl;
    }
    return 0;
}

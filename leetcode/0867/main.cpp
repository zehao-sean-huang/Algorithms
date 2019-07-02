#include "../leetcode.h"

using namespace std;

vector<vector<int> > transpose(vector<vector<int> >& A) {
    vector<vector<int> > result;
    int m = A.size(), n = A[0].size();
    for (int i = 0; i < n; ++i) {
        vector<int> r;
        for (int j = 0; j < m; ++j) {
            r.push_back(A[j][i]);
        }
        result.push_back(r);
    }
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int p = readNumber(), q = readNumber();
        vector<vector<int> > A = readGrid(p, q);
        printGrid(transpose(A));
    }
    return 0;
}
#include "../leetcode.h"

using namespace std;

vector<vector<int> > flipAndInvertImage(vector<vector<int> >& A) {
    vector<vector<int> > result = A;
    for (vector<int>& r : result) {
        reverse(r.begin(), r.end());
        for (int& n : r) {
            n = 1 - n;
        }
    }
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int n = readNumber();
    for (int i = 0; i < n; ++i) {
        int p = readNumber(), q = readNumber();
        vector<vector<int> > A = readGrid(p, q);
        printGrid(flipAndInvertImage(A));
    }
    return 0;
}
#include "../leetcode.h"

using namespace std;

void flip(int& n) {
    n = 1 - n;
}

int matrixScore(vector<vector<int> >& A) {
    int m = len(A), n = len(A[0]), sum = 0;
    for (vector<int>& r : A) {
        if (r[0] == 0) {
            for (int &n : r) {
                flip(n);
            }
        }
    }
    sum += m * int(pow(2, n - 1));
    for (int i = 1; i < n; ++i) {
        int cnt = 0;
        for (vector<int>& r : A) {
            if (r[i]) ++cnt;
        }
        sum += max(cnt, m - cnt) * int(pow(2, n - i - 1));
    }
    return sum;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int p = readNumber(), q = readNumber();
        vector<vector<int> > A = readGrid(p, q);
        cout << matrixScore(A) << endl;
    }
    return 0;
}

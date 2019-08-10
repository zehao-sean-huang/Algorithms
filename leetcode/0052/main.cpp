#include "../leetcode.h"

using namespace std;

void search(int& r, bool* c, bool* ld, bool* rd, int i, int* p, int n) {
    if (i == n) {
        r++;
        return;
    } else {
        for (int j = 0; j < n; ++j) {
            if (!c[j] && !ld[i+j] && !rd[n+i-j-1]) {
                p[i] = j;
                ld[i+j] = 1;
                rd[n+i-j-1] = 1;
                c[j] = 1;
                search(r, c, ld, rd, i+1, p, n);
                p[i] = -1;
                ld[i+j] = 0;
                rd[n+i-j-1] = 0;
                c[j] = 0;
            }
        }
    }
}

int totalNQueens(int n) {
    int pos[n+10];
    bool c[n+10];
    bool ld[n+10];
    bool rd[n+10];
    memset(c, false, sizeof(c));
    memset(ld, false, sizeof(ld));
    memset(rd, false, sizeof(rd));
    int r = 0;
    search(r, c, ld, rd, 0, pos, n);
    return r;
}


int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        cout << totalNQueens(readNumber()) << endl;
    }
    return 0;
}

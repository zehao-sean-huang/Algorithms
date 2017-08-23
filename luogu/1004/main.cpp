#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;
int g[15][15];
int r[15][15][15][15];
int N;
int max(int a, int b) {
    return a > b ? a : b;
}
int max(int a, int b, int c, int d) {
    return max(a, max(b, max(c, d)));
}
void read() {
    scanf("%d",&N);
    int x,y,n;
    scanf("%d%d%d",&x,&y,&n);
    while (x!=0||y!=0||n!=0) {
        g[x][y]=n;
        scanf("%d%d%d",&x,&y,&n);
    }
}
int main() {
    read();
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (int k = 1; k <= N; ++k) {
                for (int l = 1; l <= N; ++l) {
                    r[i][j][k][l] = max(
                        r[i - 1][j][k - 1][l],
                        r[i - 1][j][k][l - 1],
                        r[i][j - 1][k - 1][l],
                        r[i][j - 1][k][l - 1]
                    ) + g[i][j] + g[k][l];
                    if (i == k && j == l) {
                        r[i][j][k][l] -= g[i][j];
                    }
                }
            }
        }
    }
    cout << r[N][N][N][N] << endl;
    return 0;
}
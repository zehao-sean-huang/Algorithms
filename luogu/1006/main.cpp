#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int values[60][60];
int m, n;
int result[60][60][60][60];
int max(int a, int b, int c, int d) {
    return (a = (a > b ? a : b)) > (c = (c > d ? c : d)) ? a : c;
}
void start() {
    memset(result, 0, sizeof(result));
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &values[i][j]);
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int p = 1; p <= m; ++p) {
                for (int q = 1; q <= n; ++q) {
                    if (((i != p) || (j != q)) && i + j == p + q) {
                        result[i][j][p][q] = max(
                            result[i][j - 1][p][q - 1],
                            result[i - 1][j][p][q - 1],
                            result[i][j - 1][p - 1][q],
                            result[i - 1][j][p - 1][q]
                        ) + values[i][j] + values[p][q];
                    }
                }
            }
        }
    }
    cout << result[m][n - 1][m - 1][n] << endl;
}
int main() {
    start();
    return 0;
}
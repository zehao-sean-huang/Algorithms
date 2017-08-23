#include <bits/stdc++.h>
using namespace std;
int N;
int M;
int numbers[100];
int result[100][100];
int powers[100];
int ans;
int max(int a, int b) {
    return a > b ? a : b;
}
int main() {
    scanf("%d%d",&N,&M);
    powers[0] = 1;
    for (int i = 1; i <= M; ++i) {
        powers[i] = powers[i - 1] * 2;
    }
    for (int i = 1; i <= N; ++i) {
        int r = -1;
        memset(result, 0, sizeof(result));
        for (int j = 1; j <= M; ++j) {
            scanf("%d", &numbers[j]);
        }
        for (int m = 1; m <= M; ++m) {
            for (int n = M; n >= m; --n) {
                result[m][n] = max(result[m - 1][n] + numbers[m - 1] * powers[M - (n - m + 1)], result[m][n + 1] + numbers[n + 1] * powers[M - (n - m + 1)]);
            }
        }
        for (int j = 1; j <= M; ++j) {
            r = max(r, result[j][j]);
        }
        ans += r;
    }
    cout << ans << endl;
}
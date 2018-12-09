#include "../euler.h"
#define ll long long

using namespace std;

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m, n;
    ll ans;
    ll r[210][210]; // r[m][n]
    cin >> m >> n;
    memset(r, 0, sizeof(r));
    for (int i = 1; i <= m; ++i) {
        int value = 0;
        cin >> value;
        r[i - 1][0] = 1;
        for (int j = 1; j <= n; ++j) {
            for (int k = j / value; k >= 0; --k) {
                r[i][j] += r[i - 1][j - value * k];
            }
        }
    }
    cout << r[m][n] << endl;
    return 0;
}

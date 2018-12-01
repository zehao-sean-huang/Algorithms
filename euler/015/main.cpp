#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    ll r[30][30];
    memset(r, 0, sizeof(r));
    r[0][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            r[i][j] = r[i - 1][j] + r[i][j - 1];
        }
    }
    cout << r[n][n] << endl;
    return 0;
}
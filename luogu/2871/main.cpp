#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    int r[m + 1]; // r[n][m]
    memset(r, 0, sizeof(r));
    for (int i = 1; i <= n; ++i) {
        int c = 0, w = 0;
        cin >> c >> w;
        for (int j = m; j >= 0; --j) {
            r[j] = max(r[j], j >= c ? r[j - c] + w : 0);
        }
    }
    cout << r[m] << endl;
    return 0;
}
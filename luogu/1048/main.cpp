#include <bits/stdc++.h>

using namespace std;

int main() {
    int t = 0, m = 0;
    cin >> t >> m;
    int r[t + 1];
    memset(r, 0, sizeof(r));
    for (int i = 1; i <= m; ++i) {
        int c = 0, w = 0;
        cin >> c >> w;
        for (int j = t; j >= c; --j) {
            r[j] = max(r[j], r[j - c] + w);
        }
    }
    cout << r[t] << endl;
    return 0;
}
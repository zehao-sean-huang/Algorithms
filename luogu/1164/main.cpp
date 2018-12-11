#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    int r[m + 1];
    memset(r, 0, sizeof(r));
    r[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int a = 0;
        cin >> a;
        for (int j = m; j >= 0; --j) {
            r[j] += (j >= a ? r[j - a] : 0);
        }
    }
    cout << r[m] << endl;
    return 0;
}
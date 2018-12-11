#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    ll r[n + 1];
    memset(r, 0, sizeof(r));
    for (int i = 1; i <= m; ++i) {
        ll v, p;
        cin >> v >> p;
        for (int j = n; j >= v; --j) {
            r[j] = max(r[j], r[j - v] + v * p);
        }
    }
    cout << r[n] << endl;
    return 0;
}
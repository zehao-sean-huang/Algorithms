#include <bits/stdc++.h>

using namespace std;

int main() {
    int v, n;
    cin >> v >> n;
    int r[v + 1];
    memset(r, 0, sizeof(r));
    for (int i = 1; i <= n; ++i) {
        int c = 0;
        cin >> c;
        for (int j = v; j >= c; --j) {
            r[j] = max(r[j], r[j - c] + c);
            cout << r[j] << " ";
        }
        cout << endl;
    }
    cout << v - r[v] << endl;
    return 0;
}
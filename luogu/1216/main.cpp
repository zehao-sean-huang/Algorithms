#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int d[n + 10][n + 10];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> d[i][j];
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            d[i][j] += max(d[i + 1][j], d[i + 1][j + 1]);
        }
    }
    cout << d[0][0] << endl;
}
#include <bits/stdc++.h>

using namespace std;

int d[20][20];

void read() {
    memset(d, 0, sizeof(d));
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j <= i; ++j) {
            string temps;
            cin >> temps;
            d[i][j] = stoi(temps);
        }
    }
}

int main() {
    read();
    for (int i = 14; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            d[i][j] += max(d[i + 1][j], d[i + 1][j + 1]);
        }
    }
    cout << d[0][0] << endl;
    return 0;
}
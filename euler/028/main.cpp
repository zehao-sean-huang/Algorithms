#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n = 0;
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    cin >> n;
    ll sum = 0;
    for (ll i = 3; i <= n; i += 2) {
        sum += i * i * 4 - 6 * (i - 1);
    }
    cout << sum + 1 << endl;
}
#include <bits/stdc++.h>
#define ll long long

using namespace std;

map<ll, ll> computed;
ll ans = 0, maxLen = 0;

ll compute(ll n) {
    if (computed.find(n) == computed.end()) {
        if (n % 2 == 0) {
            computed[n] = 1 + compute(n / 2);
        } else {
            computed[n] = 1 + compute(3 * n + 1);
        }
    } 
    return computed[n];
}

int main() {
    computed[1] = 1;
    for (ll i = 2; i < 1000000; ++i) {
        if (compute(i) > maxLen) {
            ans = i;
            maxLen = compute(i);
        }
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
#define ll long long

using namespace std;

set<ll> primes;

bool process(ll n) {
    if (n == 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    int u = int(sqrt(n));
    for (int i = u; i > 1; --i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ll m = LLONG_MIN;
    pair<int, int> ans;
    for (int b = 2; b <= 1000; ++b) {
        for (int a = -1 * b; a < 1000; ++a) {
            ll n = 0, number = b;
            while (process(number)) {
                n++;
                number = n * n + a * n + b;
                if (number < 0) {
                    break;
                }
            }
            if (n > m) {
                ans.first = a;
                ans.second = b;
                m = n;
            }
        }
    }
    cout << ans.first << " " << ans.second << endl;
    cout << ans.first * ans.second << endl;
    return 0;
}
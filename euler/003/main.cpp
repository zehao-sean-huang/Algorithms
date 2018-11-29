#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll n = 600851475143;
    ll c = 2;
    ll ans = c;
    while (n > 1) {
        while (n % c == 0) {
            n /= c;
            ans = c;
        }
        ++c;
    }
    cout << ans << endl;
    return 0;
}
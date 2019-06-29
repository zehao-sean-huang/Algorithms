#include "../euler.h"

using namespace std;

bool square(ll n) {
    ll t = (ll)(sqrt(n));
    return t * t == n;
}

int main() {
    ll n;
    set<ll> primes;
    for (ll i = 3; ; i += 2) {
        if (!prime(i, primes)) {
            bool result = false;
            for (ll p : primes) {
                if (square((i - p) / 2)) {
                    result = true;
                    break;
                } 
            }
            if (!result) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}

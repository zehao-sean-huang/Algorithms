#include "../euler.h"

using namespace std;

set<ll> primes;

bool legit(ll n) {
    int result = 0;
    for (ll p : primes) {
        if (n % p == 0) {
            result += 1;
            while (n % p == 0) {
                n /= p;
            }
        }
        if (n == 1) {
            return result == 4;
        } else if (result >= 4) {
            return false;
        }
    }
    return false;
}

int main() {
    for (ll i = 2; ; i += 1) {
        if (!prime(i, primes)) {
            if (legit(i) && legit(i - 1) && legit(i - 2) && legit(i - 3)) {
                cout << i << " " << i - 1 << " " << i - 2 << " " << i - 3 << endl;
                break;
            }
        }
    }
    return 0;
}

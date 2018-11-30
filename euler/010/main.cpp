#include <bits/stdc++.h>
#define ll long long

using namespace std;

set<int> primes;

ll ans = 5;

void process(int n) {
    bool r = true;
    for (int p : primes) {
        if (n % p == 0) {
            r = false;
            break;
        }
    }
    if (r) {
        primes.insert(n);
        ans += n;
    }
}

int main() {
    int k = 1;
    primes.insert(2);
    primes.insert(3);
    for (int k = 1; k <= 333333; ++k) {
        process(6 * k - 1);
        process(6 * k + 1);
    }
    cout << ans << endl;
    return 0;
}
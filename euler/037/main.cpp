#include "../euler.h"

using namespace std;

set<ll> primes;

bool judge(ll n) {
    if (!prime(n, primes)) {
        return false;
    }
    if (n < 10) {
        return false;
    }
    string s = str(n);
    for (int i = 1; i < s.size(); ++i) {
        if (!prime(stoll(s.substr(i, s.size() - i)), primes)) {
            return false;
        }
        if (!prime(stoll(s.substr(0, s.size() - i)), primes)) {
            return false;
        }
    }
    return true;
}

int main() {
    ll n = 2, ans = 0, cnt = 0;
    while (++n && cnt != 11) {
        if (judge(n)) {
            cout << n << endl;
            ++cnt;
            ans += n;
        }
        if (n > 10000000) break;
    }
    cout << ans << endl;
    return 0;
}

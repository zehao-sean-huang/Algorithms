#include "../euler.h"

using namespace std;

set<ll> primes;
int ans = 0;

void judge(ll n) {
    string s = str(n);
    set<ll> candidates;
    for (int i = 1; i < s.size(); ++i) {
        s = s.substr(1, s.size() - 1) + s[0];
        if (!prime(stoi(s), primes)) {
            return;
        }
        candidates.insert(stoi(s));
    }
    cout << n << endl; 
    ++ans;
}

int main() {
    for (ll i = 2; i < 1000000; ++i) {
        if (prime(i, primes)) {
            judge(i);
        }
    }
    cout << ans << endl;
    return 0;
}
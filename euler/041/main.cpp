#include "../euler.h"

using namespace std;

set<ll> primes;
string pan = "123456789";
ll ans = 0;

void permute(string s, ll current) {
    if (!len(s)) {
        if (prime(current, primes)) {
            ans = max(ans, current);
        }
        return;
    }
    for (int i = 0; i < len(s); ++i) {
        permute(s.substr(0, i) + s.substr(i + 1, len(s) - i - 1), 10 * current + ord(s[i]));
    }
}

int main() {
    for (int i = len(pan); i > 0; --i) {
        string s = pan.substr(0, i);
        permute(s, 0);
        if (ans > 0) break;
    }
    cout << ans << endl;
}

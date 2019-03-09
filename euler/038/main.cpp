#include "../euler.h"

using namespace std;

ll ans = 0;

void process(ll i) {
    string s = "";
    ll n = 1;
    while (s.size() < 9) {
        s += str((n++) * i);
    }
    ll r = stoll(s);
    sort(s.begin(), s.end());
    if (s == "123456789") {
        cout << i << " " << r << endl;
        ans = max(r, ans);
    }
}

int main() {
    ll limit = 10000;
    for (ll i = i; i < limit; ++i) {
        process(i);
    }
    cout << ans << endl;
    return 0;
}
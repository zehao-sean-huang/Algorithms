#include "../euler.h"

using namespace std;

bool valid(ll n) {
    ll t1 = (ll)(sqrt(8 * n + 1));
    ll t2 = (ll)(sqrt(24 * n + 1));
    if (t1 * t1 == 8 * n + 1 && t2 * t2 == 24 * n + 1) {
        return ((t1 - 1) % 2 == 0) && ((t2 + 1) % 6 == 0) && ((t1 + 1) % 4 == 0);
    } else {
        return false;
    }
}

int main() {
    for (ll i = 1; ; ++i) {
        if (valid(i)) {
            cout << i << endl;
            if (i > 40755) {
                break;
            }
        }
        if (i % 100000000 == 0) {
            cout << "checking " << i << endl;
        }
    }
    return 0;
}

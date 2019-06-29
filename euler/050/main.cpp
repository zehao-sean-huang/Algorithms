#include "../euler.h"

using namespace std;

int main() {
    set<ll> primes;
    ll limit = 1000000;
    ll numbers[100010];
    int size = 1;
    for (ll i = 2; i < limit; ++i) {
        if (prime(i, primes)) {
            numbers[size++] = i;
        }
    }
    for (int length = 21; length < 600; length += 1) {
        ll sum = 0;
        for (int i = 0; i < length; ++i) sum += numbers[i];
        for (int i = 1; i <= size - length + 1; ++i) {
            sum = sum - numbers[i - 1] + numbers[i + length - 1];
            if (primes.find(sum) != primes.end()) {
                cout << length << " " << sum << endl;
                break;
            }
        }
    }
    return 0;
}

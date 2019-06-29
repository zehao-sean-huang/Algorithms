#include "../euler.h"

using namespace std;

set<ll> primes;

bool permutation(int a, int b) {
    int counter[10];
    memset(counter, 0, sizeof(counter));
    while (a) {
        counter[a % 10] += 1;
        a /= 10;
    }
    while (b) {
        counter[b % 10] -= 1;
        b /= 10;
    }
    for (int i = 0; i < 10; ++i) {
        if (counter[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> numbers;
    for (ll i = 2; i < 10000; ++i) {
        if (prime(i, primes) && i > 1000) {
            numbers.push_back(i);
        }
    }
    for (int i = 0; i < numbers.size(); ++i) {
        for (int j = i + 1; j < numbers.size(); ++j) {
            int a = numbers[i], b = numbers[j];
            int c = 2 * b - a;
            if (c < 10000 && primes.find(c) != primes.end()) {
                if (permutation(a, b) && permutation(b, c)) {
                    cout << a << b << c << endl;
                }
            }
        }
    }
    return 0;
}

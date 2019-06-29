#include "../euler.h"

using namespace std;

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

bool valid(ll i) {
    return permutation(i, 2 * i) 
        && permutation(i, 3 * i)
        && permutation(i, 4 * i)
        && permutation(i, 5 * i)
        && permutation(i, 6 * i);
}

int main() {
    bool found = false;
    for (int power = 2; ; ++power) {
        ll limit = pow(10, power);
        ll start = limit;
        for (int i = 0; i < power; ++i) limit += 6 * pow(10, i);
        cout << "power: " << power << " start: " << start << " limit: " << limit << endl;
        for (int i = start; i < limit; ++i) {
            if (valid(i)) {
                cout << i << endl;
                found = true;
                break;
            }
        }
        if (found) break;
    }
    return 0;
}

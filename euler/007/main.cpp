#include <bits/stdc++.h>

using namespace std;

int main() {
    int cnt = 1;
    int cur = 2;
    set<int> primes;
    bool pri = true;
    primes.insert(cur);
    while (cnt != 10001) {
        cur++;
        for (int p : primes) {
            if (cur % p == 0) {
                pri = false;
                break;
            }
        }
        if (pri) {
            primes.insert(cur);
            cnt++;
        }
        pri = true;
    }
    cout << cur << endl;
}
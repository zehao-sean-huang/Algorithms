#include <bits/stdc++.h>

using namespace std;

int cache[10010];

int calculate(int n) {
    int ans = 0;
    for (int i = 1; i < int(sqrt(n)) + 1; ++i) {
        if (n % i == 0) {
            ans += i + n / i;
        }
        if (i * i == n) {
            ans -= i;
        }
    }
    return ans - n;
}

int main() {
    int ans = 0;
    for (int i = 1; i < 10000; ++i) {
        cache[i] = calculate(i);
        if (cache[i] < i) {
            if (cache[cache[i]] == i) {
                ans += cache[i] + i;
            }
        }
    }
    cout << ans << endl;
}
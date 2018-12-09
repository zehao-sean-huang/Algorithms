#include <bits/stdc++.h>

using namespace std;

int cache[10];

bool judge(int n) {
    int m = n, sum = 0;
    while (m != 0) {
        sum += cache[m % 10];
        m /= 10;
    }
    return sum == n;
}

int main() {
    for (int i = 0; i < 10; ++i) {
        cache[i] = int(pow(i, 5));
    }
    int ans = 0;
    for (int i = 10; i <= 354294; ++i) {
        if (judge(i)) {
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}

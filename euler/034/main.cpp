#include "../euler.h"

using namespace std;

int cache[10];

bool judge(int n) {
    int m = n, sum = 0;
    while (m) {
        sum += cache[m % 10];
        m /= 10;
    }
    return sum == n;
}

int main() {
    memset(cache, 0, sizeof(cache));
    cache[0] = 1;
    for (int i = 1; i < 10; ++i) {
        cache[i] = i * cache[i - 1];
    }
    int ans = 0;
    for (int i = 10; i < 2540160; ++i) {
        if (judge(i)) {
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}

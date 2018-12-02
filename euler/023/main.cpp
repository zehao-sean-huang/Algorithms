#include <bits/stdc++.h>

using namespace std;

set<int> abundant;

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

bool judge(int n) {
    for (int number : abundant) {
        if (abundant.find(n - number) != abundant.end()) {
            return true;
        }
    }
    return false;
}

int main() {
    int ans = 0;
    for (int i = 1; i <= 28123; ++i) {
        if (!judge(i)) {
            ans += i;
        }
        if (calculate(i) > i) {
            abundant.insert(i);
        }
    }
    cout << ans << endl;
    return 0;
}

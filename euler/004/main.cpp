#include <bits/stdc++.h>

using namespace std;

bool check(int n) {
    string s = string(to_string(n));
    int c = s.size();
    for (int i = 0; i < c / 2; ++i) {
        if (s[i] != s[c - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int ans = INT_MIN;
    for (int i = 999; i >= 100; --i) {
        for (int j = i; j >= 100; --j) {
            if (check(i * j)) {
                ans = max(ans, i * j);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
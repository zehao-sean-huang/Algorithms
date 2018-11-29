#include <bits/stdc++.h>

using namespace std;

int main() {
    int ans;
    for (int i = 1; i < 1000; ++i) {
        if ((i / 3) * 3 == i || (i / 5) * 5 == i) {
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}

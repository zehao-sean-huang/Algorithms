#include <bits/stdc++.h>

using namespace std;

int main() {
    int temp = 0;
    int prev = 1;
    int current = 2;
    int ans = current;
    while (current < 4000000) {
        temp = current;
        current = prev + current;
        prev = temp;
        if (current % 2 == 0) {
            ans += current;
        }
    }
    cout << ans << endl;
    return 0;
}

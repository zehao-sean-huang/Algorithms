#include <bits/stdc++.h>

using namespace std;

int main() {
    int r1 = 0, r2 = 0;
    for (int i = 1; i <= 100; ++i) {
        r1 += i * i;
        r2 += i;
    }
    cout << r2 * r2 - r1 << endl;
}
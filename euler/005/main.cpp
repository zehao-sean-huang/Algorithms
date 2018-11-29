#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 2520;
    for (int i = 11; i <= 20; ++i) {
        int c = n;
        for (int j = i; j >= 1; --j) {
            if (c % j == 0 && i % j == 0) {
                n *= (i / j);
                break;
            }
        }
    }
    cout << n << endl;
    return 0;
}
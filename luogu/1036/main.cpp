#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int a[30];
int n, k;
int r = 0;

bool prime(int n) {
    if (n == 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    int u = int(sqrt(n));
    for (int i = u; i > 1; --i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void read() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

void help(int cnt, int sum, int index) {
    if (cnt == k) {
        if (prime(sum)) {
            ++r;
        }
        return;
    }
    for (int i = index; i <= (n + cnt - k); ++i) {
        help(cnt + 1, sum + a[i], i + 1);
    }
}

int main() {
    read();
    for (int i = 0; i <= (n - k); ++i) {
        help(1, a[i], i + 1);
    }
    cout << r << endl;
    return 0;
}
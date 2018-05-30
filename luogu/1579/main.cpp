#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int n;

bool prime(int n) {
    if (n == 2) return true;
    if (n == 1) return false;
    int l = int(sqrt(n));
    for (int i = l; i >= 2; --i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 2; i < int(n / 3); ++i) {
        if (prime(i)) {
            for (int j = i; j < int(n / 3); ++j) {
                if (prime(j) && prime(n - i - j)) {
                    cout << i << " " << j << " " << (n - i - j) << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
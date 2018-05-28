#include <iostream>
#include <cmath>

using namespace std;

int n;
int r = 0;

int v(int n) {
    int t[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int s = 0;
    while (n / 10) {
        s += t[n % 10];
        n /= 10;
    }
    s += t[n];
    return s;
}

int main() {
    cin >> n;
    n -= 4;
    for (int i = 0; i < 1111; ++i) {
        for (int j = 0; j < 1111; ++j) {
            if (v(i) + v(j) + v(i + j) == n) {
                r++;
            }
        }
    }
    cout << r << endl;
    return 0;
}
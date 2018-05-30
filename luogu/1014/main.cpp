#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int n;

int main() {
    cin >> n;
    int s = int(sqrt(2 * n + 0.25) - 0.5);
    int l = n - s * (s + 1) / 2;
    if (l == 0) {
        if (s % 2) {
            cout << 1 << "/" << s << endl;
        } else {
            cout << s << "/" << 1 << endl;
        }
    } else {
        if ((s + 1) % 2) {
            cout << (s + 2 - l) << "/" << l << endl;
        } else {
            cout << l << "/" << (s + 2 - l) << endl;
        }
    }
    return 0;
}
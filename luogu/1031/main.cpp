#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int a[120];
int s = 0;
int r = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
    }
    s /= n;
    for (int i = 0; i < n; ++i) {
        a[i] -= s;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (a[i]) {
            a[i + 1] += a[i];
            ++r;
        }
    }
    cout << r << endl;
    return 0;
}
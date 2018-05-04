#include <iostream>

using namespace std;

int main() {
    int a[20];
    int h = 0;
    for (int i = 1; i <= 10; ++i) {
        cin >> a[i];
    }
    cin >> h;
    int r = 0;
    for (int i = 1; i <= 10; ++i) {
        if (a[i] <= (h + 30)) {
            r++;
        }
    }
    cout << r << endl;
    return 0;
}

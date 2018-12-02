#include <bits/stdc++.h>

using namespace std;

bool leap(int y) {
    if (y % 4 != 0) {
        return false;
    } else if (y % 100 == 0 && y % 400 != 0) {
        return false;
    } 
    return true;
}

int calculate(int y, int m) {
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    } else if (m != 2) {
        return 31;
    } else {
        if (leap(y)) {
            return 29;
        } else {
            return 28;
        }
    }
}

int main() {
    int count = 0, ans = 0;
    for (int i = 1901; i <= 2000; ++i) {
        for (int j = 1; j <= 12; ++j) {
            count += calculate(i, j);
            if (count % 7 == 4) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
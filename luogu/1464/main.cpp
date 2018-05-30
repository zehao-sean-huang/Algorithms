#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

long r[25][25][25];

long long a, b, c;

long long v(long long a, long long b, long long c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    } else if (a > 20 || b > 20 || c > 20) {
        return v(20, 20, 20);
    } else {
        long long m1 = (r[a - 1][b][c] != -1) ? r[a - 1][b][c] : (r[a - 1][b][c] = v(a - 1, b, c));
        long long m2 = (r[a - 1][b - 1][c] != -1) ? r[a - 1][b - 1][c] : (r[a - 1][b - 1][c] = v(a - 1, b - 1, c));
        long long m3 = (r[a - 1][b][c - 1] != -1) ? r[a - 1][b][c - 1] : (r[a - 1][b][c - 1] = v(a - 1, b, c - 1));
        long long m4 = (r[a - 1][b - 1][c - 1] != -1) ? r[a - 1][b - 1][c - 1] : (r[a - 1][b - 1][c - 1] = v(a - 1, b - 1, c - 1));
        return m1 + m2 + m3 - m4;
    }
}

int main() {
    memset(r, -1, sizeof(r));
    cin >> a >> b >> c;
    while (a != -1 || b != -1 || c != -1) {
        cout << "w(" << a << ", " << b << ", " << c << ") = ";
        cout << v(a, b, c) << endl;
        cin >> a >> b >> c;
    }
    return 0;
}
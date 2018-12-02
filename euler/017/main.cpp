#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int r[1010];
    ll ans = 0;
    memset(r, -1, sizeof(r));
    r[1] = 3; r[2] = 3; r[3] = 5; r[4] = 4; r[5] = 4;
    r[6] = 3; r[7] = 5; r[8] = 5; r[9] = 4; r[10] = 3;
    r[11] = 6; r[12] = 6; r[13] = 8; r[14] = 8; r[15] = 7;
    r[16] = 7; r[17] = 9; r[18] = 8; r[19] = 8; r[20] = 6;
    r[30] = 6; r[40] = 5; r[50] = 5; r[60] = 5; r[70] = 7;
    r[80] = 6; r[90] = 6; r[1000] = 11;
    for (int i = 1; i <= 1000; ++i) {
        if (r[i] == -1) {
            if (i > 20 && i < 100) {
                r[i] = r[i - i % 10] + r[i % 10];
            } else if (i % 100 == 0) {
                r[i] = 7 + r[i / 100];
            } else {
                r[i] = r[100 * (i / 100)] + 3 + r[i % 100];
            }
        }
        ans += r[i];
    }   
    cout << r[42] << endl;
    cout << r[300] << endl;
    cout << r[342] << endl;
    cout << r[115] << endl;
    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <cstring>

using namespace std;

int t[10010];

int main() {
    memset(t, 1, sizeof(t));
    int l = 0;
    int cnt = 0;
    cin >> l >> cnt;
    int r = l + 1;
    for (int i = 1; i <= cnt; ++i) {
        int a, b;
        cin >> a >> b;
        for (int j = a; j <= b; ++j) {
            if (t[j]) {
                --r;
                t[j] = 0;
            }
        }
    }
    cout << r << endl;
    return 0;
}

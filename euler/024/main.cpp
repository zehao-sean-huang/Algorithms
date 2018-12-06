#include <bits/stdc++.h>

using namespace std;

int main() {
    int f[20];
    bool used[20];
    int index = 1000000;
    memset(f, 0, sizeof(f));
    memset(used, false, sizeof(used));
    f[0] = 1;
    for (int i = 1; i <= 10; ++i) {
        f[i] = i * f[i - 1];
    }
    for (int i = 9; i >= 0; --i) {
        int cnt = (index - 1) / f[i];
        for (int j = 0; j < 10; ++j) {
            if (!used[j]) {
                if (cnt == 0) {
                    cout << j;
                    used[j] = true;
                    break;
                } else {
                    --cnt;
                }
            }
        }
        index = (index - 1) % f[i] + 1;
    }
    cout << endl;
    return 0;
}
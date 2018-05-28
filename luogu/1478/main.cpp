#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int n = 0, s = 0;
int a = 0, b = 0;
int r[5010][1010];

struct apple {
    int x;
    int y;
};

apple p[5010];

int max(int m, int n) { 
    return m > n ? m : n;
}

void init() {
    cin >> n >> s;
    cin >> a >> b;
    memset(r, 0, sizeof(r));
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }
    for (int j = p[0].y; j <= s; ++j) {
        if (p[0].x <= (a + b)) {
            r[0][j] = 1;
        }
    }
}

int main() {
    init();
    for (int i = 1; i < n; ++i) {
        if (p[i].x <= (a + b)) {
            for (int j = 0; j < p[i].y; ++j) {
                r[i][j] = r[i - 1][j];
            } 
            for (int j = p[i].y; j <= s; ++j) {
                r[i][j] = max(r[i - 1][j], r[i - 1][j - p[i].y] + 1);
            }
        } else {
            for (int j = 0; j <= s; ++j) {
                r[i][j] = r[i - 1][j];
            }
        }
    }
    if (n > 0) {
        cout << r[n - 1][s] << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
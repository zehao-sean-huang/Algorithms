#include "../euler.h"

using namespace std;

int mx = 0, ans = 0;

void process(int p) {
    int cnt = 0;
    for (int c = p / 2; c > p / 3; --c) {
        for (int a = 1; a <= (p - c) / 2; ++a) {
            int b = p - c - a;
            if (a*a + b*b == c*c) {
                cout << p << " " << a << " " 
                    << b << " " << c << " " << endl;
                ++cnt;
            }
        } 
    }
    if (cnt > mx) {
        mx = cnt;
        ans = p;
    }
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    freopen("main.out", "w", stdout);
    #endif
    int limit = 1000;
    for (int i = 1; i < limit; ++i) {
        process(i);
    }
    cout << ans << endl;
    return 0;
}

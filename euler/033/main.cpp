#include "../euler.h"

using namespace std;

int above = 1, below = 1;

bool judge(int i, int j) {
    int p = 0, q = 0;
    if (i / 10 == j % 10) {
        p = i % 10; q = j / 10;
    } else if (i % 10 == j / 10) {
        p = i / 10; q = j % 10;
    } else {
        return false;
    }
    if (p * j == i * q) {
        above *= p;
        below *= q;
    }
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    for (int i = 10; i < 100; ++i) {
        for (int j = i + 1; j < 100; ++j) {
            judge(i, j);
        }
    }
    cout << above << " " << below << endl;
    return 0;
}
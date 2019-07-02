#include "../leetcode.h"

using namespace std;

int cache[40];

int fib(int N) {
    cache[0] = 0;
    cache[1] = 1;
    for (int i = 2; i <= N; ++i) cache[i] = cache[i - 1] + cache[i - 2];
    return cache[N];
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        // test case
    }
    return 0;
}

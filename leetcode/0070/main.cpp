#include "../leetcode.h"

using namespace std;

map<int, int> computed;
int climbStairs(int n) {
    if (n == 1 || n == 2) {
        return n;
    } else if (computed.find(n) == computed.end()) {
        computed[n] = climbStairs(n - 1) + climbStairs(n - 2);
    } 
    return computed[n];
}

int main() {
    int n;
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    while (cin >> n) {
        cout << n << " " << climbStairs(n) << endl;
    }
    return 0;
}
#include "../leetcode.h"

using namespace std;

vector<int> countBits(int num) {
    vector<int> result(num + 1, 0); 
    result[0] = 0;
    for (int i = 1; i <= num; ++i) {
        result[i] = result[i / 2] + i % 2;
    }
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int n = readNumber();
        printVector(countBits(n));
    }
    return 0;
}
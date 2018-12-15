#include "../leetcode.h"

using namespace std;

int hammingDistance(int n1, int n2) { 
    int x = n1 ^ n2; 
    int setBits = 0; 
    while (x > 0) { 
        setBits += x & 1; 
        x >>= 1; 
    } 
    return setBits; 
} 

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int x = readNumber(), y = readNumber();
        cout << hammingDistance(x, y) << endl;
    }
    return 0;
}

#include "../leetcode.h"

using namespace std;

bool stoneGame(vector<int> &piles) {
    return true;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<int> piles = readVector(readNumber());
        cout << (stoneGame(piles) ? "true" : "false") << endl;
    }
    return 0;
}

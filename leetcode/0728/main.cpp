#include "../leetcode.h"

using namespace std;

bool judge(int n) {
    for (char c : str(n)) {
        if (!ord(c)) return false;
        if (n % ord(c)) return false;
    }
    return true;
}

vector<int> selfDividingNumbers(int left, int right) {
    vector<int> result;
    for (int i = left; i <= right; ++i) {
        if (judge(i)) result.push_back(i);
    }
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int left = readNumber(), right = readNumber();
        printVector(selfDividingNumbers(left, right));
    }
    return 0;
}

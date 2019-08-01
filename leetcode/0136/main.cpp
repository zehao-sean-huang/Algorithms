#include "../leetcode.h"

using namespace std;

int singleNumber(vector<int>& nums) {
    int r = 0;
    for (int n : nums) r ^= n;
    return r;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<int> nums = readVector();
        cout << singleNumber(nums) << endl;
    }
    return 0;
}

#include "../leetcode.h"

using namespace std;

int rob(vector<int> nums) {
    if (nums.empty()) {
        return 0;
    }
    int n = nums.size(), r[n + 10];
    r[1] = nums[0];
    for (int i = 2; i <= n; ++i) {
        r[i] = max(nums[i - 1] + r[i - 2], r[i - 1]);
    }
    return r[n];
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    cout << rob(readVector(5)) << endl;
    return 0;
}
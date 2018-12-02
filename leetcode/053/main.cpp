#include "../leetcode.h"

using namespace std;

int maxSubArray(vector<int> nums) {
    if (nums.empty()) {
        return 0;
    } else if (nums.size() == 1) {
        return nums[0];
    } else {
        int mid = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());
        int rl = maxSubArray(left);
        int rr = maxSubArray(right);
        int ltm = INT_MIN, rtm = INT_MIN, ls = 0, rs = 0;
        for (int i = left.size() - 1; i >= 0; --i) {
            ls += left[i];
            ltm = max(ltm, ls);
        }
        for (int i = 0; i < right.size(); ++i) {
            rs += right[i];
            rtm = max(rtm, rs);
        }
        return max(ltm + rtm, max(rl, rr));
    }
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    cout << maxSubArray(readVector(9)) << endl;
    return 0;
}
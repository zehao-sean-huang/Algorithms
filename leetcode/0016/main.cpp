#include "../leetcode.h"

using namespace std;

int threeSumClosest(vector<int> &nums, int target) {
    int dist = INT_MAX, ans = 0;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n - 2; ++i) {
        if (i > 0 and nums[i - 1] == nums[i]) continue;
        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum < target) ++l;
            else --r;
            if (dist > abs(sum - target)) {
                dist = abs(sum - target);
                ans = sum;
            }
        }
    }
    return ans;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<int> nums = readVector();
        cout << threeSumClosest(nums, readNumber()) << endl;
    }
    return 0;
}

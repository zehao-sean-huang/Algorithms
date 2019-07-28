#include "../leetcode.h"

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n - 3; ++i) {
        if (nums[i] * 4 > target) break;
        if (i > 0 && nums[i - 1] == nums[i]) continue;
        for (int j = i + 1; j < n - 2; ++j) {
            if (j > i + 1 and nums[j - 1] == nums[j]) continue;
            int l = j + 1;
            int r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[j] + nums[l] + nums[r];
                if (sum < target) ++l;
                else if (sum > target) --r;
                else {
                    result.push_back({nums[i], nums[j], nums[l++], nums[r--]});
                    while (l < r and nums[l] == nums[l - 1]) l++;
                    while (l < r and nums[r] == nums[r + 1]) r--;
                }
            }
        }
    }
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<int> nums = readVector();
        printGrid(fourSum(nums, readNumber()));
    }
    return 0;
}

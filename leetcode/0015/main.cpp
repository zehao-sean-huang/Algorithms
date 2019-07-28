#include "../leetcode.h"

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n - 2; ++i) {
        if (nums[i] > 0) break;
        if (i > 0 and nums[i - 1] == nums[i]) continue;
        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum < 0) ++l;
            else if (sum > 0) --r;
            else {
                result.push_back({nums[i], nums[l++], nums[r--]});
                while(l < r and nums[l] == nums[l - 1]) l++;
                while(l < r and nums[r] == nums[r + 1]) r--;
            }
        }
        while (i + 1 < n - 2 && nums[i] == nums[i + 1]) i += 1;
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
        printGrid(threeSum(nums));
    }
    return 0;
}

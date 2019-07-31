#include "../leetcode.h"

using namespace std;

void search(vector<int>& nums, int t, int s, int e, int &r, bool left) {
    if (s > e) return;
    if (s == e) {
        if (nums[s] == t && r == -1) {
            r = s;
        }
        return;
    }
    int m = (s + e) >> 1;
    if (nums[m] == t && nums[m + 1] == t) {
        if (left) {
            search(nums, t, s, m, r, left);
        } else {
            search(nums, t, m + 1, e, r, left);
        }
    } else if (t <= nums[m]) {
        search(nums, t, s, m, r, left);
    } else {
        search(nums, t, m + 1, e, r, left);
    }
}

vector<int> searchRange(vector<int>& nums, int target) {
    int l = -1, r = -1;
    search(nums, target, 0, nums.size() - 1, l, true);
    search(nums, target, 0, nums.size() - 1, r, false);
    return {l, r};
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<int> nums = readVector();
        int target = readNumber();
        printVector(searchRange(nums, target));
    }
    return 0;
}

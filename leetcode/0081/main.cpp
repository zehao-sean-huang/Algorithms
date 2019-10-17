#include "../leetcode.h"

using namespace std;

bool search(vector<int>& nums, int target, int start, int end) {
    if (start > end) return false;
    if (start < 0 || end >= nums.size()) return false;
    if (start == end) return nums[start] == target;
    int mid = (start + end) / 2;
    if (nums[start] <= target && target <= nums[mid]) {
        return search(nums, target, start, mid);
    } else if (nums[mid + 1] <= target && target <= nums[end]) {
        return search(nums, target, mid + 1, end);
    } else {
        return search(nums, target, start, mid) || search(nums, target, mid + 1, end);
    }
}

bool search(vector<int>& nums, int target) {
    return search(nums, target, 0, nums.size() - 1);
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<int> nums = readVector();
        int target = readNumber();
        cout << (search(nums, target) ? "true" : "false") << endl;
    }
    return 0;
}

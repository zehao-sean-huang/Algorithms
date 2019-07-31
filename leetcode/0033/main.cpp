#include "../leetcode.h"

using namespace std;

void search(vector<int>& nums, int target, int start, int end, int &result) {
    if (start > end) return;
    if (start == end) {
        if (nums[start] == target) result = start;
        return;
    }
    int mid = (start + end) >> 1;
    if (nums[start] <= target && target <= nums[mid]) {
        search(nums, target, start, mid, result);
    } else if (nums[mid + 1] <= target && target <= nums[end]) {
        search(nums, target, mid + 1, end, result);
    } else {
        search(nums, target, start, mid, result);
        search(nums, target, mid + 1, end, result);
    }
}

int search(vector<int>& nums, int target) {
    int result = -1;
    search(nums, target, 0, nums.size() - 1, result);
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<int> nums = readVector();
        int target = readNumber();
        cout << search(nums, target) << endl;
    }
    return 0;
}

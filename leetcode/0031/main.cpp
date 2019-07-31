#include "../leetcode.h"

using namespace std;

void swap(vector<int> &nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;
    while (i >= 0 && nums[i + 1] <= nums[i]) {
        i--;
    }
    if (i >= 0) {
        int j = nums.size() - 1;
        while (j >= 0 && nums[j] <= nums[i]) {
            j--;
        }
        swap(nums, i, j);
    }
    int j = nums.size() - 1;
    i += 1;
    while (i < j) {
        swap(nums, i, j);
        i++;
        j--;
    }
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<int> nums = readVector();
        nextPermutation(nums);
        printVector(nums);
    }
    return 0;
}

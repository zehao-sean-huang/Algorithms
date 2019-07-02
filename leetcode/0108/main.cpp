#include "../leetcode.h"

using namespace std;

TreeNode* sortedArrayToBSTHelper(vector<int>&nums, int left, int right) {
    if (left > right) {
        return nullptr;
    } else if (left == right) {
        return new TreeNode(nums[left]);
    } else {
        int m = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = sortedArrayToBSTHelper(nums, left, m - 1);
        root->right = sortedArrayToBSTHelper(nums, m + 1, right);
        return root;
    }
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int n = 0;
    while (cin >> n) {
        vector<int> nums = readVector(n);
        printBinaryTree(sortedArrayToBST(nums));
    }
    return 0;
}

#include "../leetcode.h"

using namespace std;

TreeNode* constructMaximumBinaryTreeHelper(vector<int>& nums, int l, int r) {
    if (l > r) {
        return nullptr;
    } else if (l == r) {
        return new TreeNode(nums[l]);
    } else {
        int index = 0, max = 0;
        for (int i = l; i <= r; ++i) {
            if (nums[i] > max) {
                index = i;
                max = nums[i];
            }
        }
        TreeNode* root = new TreeNode(max);
        root->left = constructMaximumBinaryTreeHelper(nums, l, index - 1);
        root->right = constructMaximumBinaryTreeHelper(nums, index + 1, r);
        return root;
    }
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return constructMaximumBinaryTreeHelper(nums, 0, nums.size() - 1);
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    vector<int> nums = readVector(6);
    printBinaryTree(constructMaximumBinaryTree(nums));
    return 0;
}
#include "../leetcode.h"

using namespace std;

int sum(TreeNode* root) {
    if (root == nullptr) return 0;
    return root->val + sum(root->left) + sum(root->right);
}

int findTilt(TreeNode* root) {
    if (root == nullptr) return 0;
    int left = sum(root->left);
    int right = sum(root->right);
    return max(left, right) - min(left, right) + findTilt(root->left) + findTilt(root->right);
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        cout << findTilt(readBinaryTree()) << endl;
    }
    return 0;
}
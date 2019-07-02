#include "../leetcode.h"

using namespace std;

bool isValidBST(TreeNode* root, long long min, long long max) {
    if (root == nullptr) {
        return true;
    }
    if (root->val >= max || root->val <= min) {
        return false;
    }
    return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
}

bool isValidBST(TreeNode* root) {
    return isValidBST(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    cout << (isValidBST(readBinaryTree()) ? "true" : "false") << endl;
    return 0;
}
#include "../leetcode.h"

using namespace std;

bool hasPathSum(TreeNode* root, int sum) {
    if (root == nullptr) {
        return false;
    }
    if (root->left == nullptr && root->right == nullptr) {
        if (root->val == sum) {
            return true;
        }
    }
    bool result = false;
    if (root->left != nullptr) {
        result = result || hasPathSum(root->left, sum - root->val);
    }
    if (root->right != nullptr) {
        result = result || hasPathSum(root->right, sum - root->val);
    }
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    cout << (hasPathSum(readBinaryTree(), readNumber()) ? "true" : "false") << endl;
    return 0;
}
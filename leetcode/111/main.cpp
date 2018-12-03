#include "../leetcode.h"

using namespace std;

int minDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    } else if (root->left == nullptr && root->right == nullptr) {
        return 1;
    } else if (root->left == nullptr) {
        return 1 + minDepth(root->right);
    } else if (root->right == nullptr) {
        return 1 + minDepth(root->left);
    } else {
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    cout << minDepth(readBinaryTree()) << endl;
    return 0;
}
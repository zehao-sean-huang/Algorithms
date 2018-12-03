#include "../leetcode.h"

using namespace std;

int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    } else if (root->left == nullptr && root->right == nullptr) {
        return 1;
    } else if (root->left == nullptr) {
        return maxDepth(root->right) + 1;
    } else if (root->right == nullptr) {
        return maxDepth(root->left) + 1;
    } else {
        return max(maxDepth(root->right), maxDepth(root->left)) + 1;
    }
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    cout << maxDepth(readBinaryTree()) << endl;
    return 0;
}
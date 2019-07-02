#include "../leetcode.h"

using namespace std;

TreeNode* pruneTree(TreeNode* root) {
    if (root->left != nullptr) {
        root->left = pruneTree(root->left);
    }
    if (root->right != nullptr) {
        root->right = pruneTree(root->right);
    }
    if (root->left == nullptr && root->right == nullptr) {
        if (root->val == 0) {
            root = nullptr;
        }
    }
    return root;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int n = readNumber();
    for (int i = 0; i < n; ++i) {
        printBinaryTree(pruneTree(readBinaryTree()));
    }
    return 0;
}


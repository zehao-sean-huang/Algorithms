#include "../leetcode.h"

using namespace std;

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (val < root->val) {
        if (root->left == nullptr) {
            root->left = new TreeNode(val);
        } else {
            insertIntoBST(root->left, val);
        }
    } else {
        if (root->right == nullptr) {
            root->right = new TreeNode(val);
        } else {
            insertIntoBST(root->right, val);
        }
    }
    return root;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    TreeNode* root = readBinaryTree();
    int n = readNumber();
    printBinaryTree(insertIntoBST(root, n));
    return 0;
}
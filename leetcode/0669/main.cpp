#include "../leetcode.h"

using namespace std;

TreeNode* trimBST(TreeNode* root, int L, int R) {
    if (root == nullptr) {
        return nullptr;
    }
    int &v = root->val;
    if (v < L) {
        return trimBST(root->right, L, R);
    } else if (v > R) {
        return trimBST(root->left, L, R);
    } else {
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        TreeNode* root = readBinaryTree();
        int l = readNumber(), r = readNumber();
        printBinaryTree(trimBST(root, l, r));
    }
    return 0;
}
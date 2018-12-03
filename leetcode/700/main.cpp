#include "../leetcode.h"

using namespace std;    

TreeNode* searchBST(TreeNode* root, int val) {
    if (root == nullptr) {
        return root;
    } else if (root->val == val) {
        return root;
    } else if (val < root->val) {
        return searchBST(root->left, val);
    } else {
        return searchBST(root->right, val);
    }
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    TreeNode* root = readBinaryTree();
    int n = readNumber();
    printBinaryTree(searchBST(root, n));
    return 0;
}
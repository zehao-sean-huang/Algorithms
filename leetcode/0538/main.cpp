#include "../leetcode.h"

using namespace std;

void helper(TreeNode* root, int &previous) {
    if (root != nullptr) {
        helper(root->right, previous);
        root->val += previous;
        previous = root->val;
        helper(root->left, previous);
    }
}

TreeNode* convertBST(TreeNode* root) {
    int previous = 0;
    helper(root, previous);
    return root;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        printBinaryTree(convertBST(readBinaryTree()));
    }
    return 0;
}
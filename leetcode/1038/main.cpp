#include "../leetcode.h"

using namespace std;

void help(TreeNode* root, int &sum) {
    if (root == nullptr) {
        return;
    }
    help(root->right, sum);
    root->val += sum;
    sum = root->val;
    help(root->left, sum);
}

TreeNode* bstToGst(TreeNode* root) {
    if (root == nullptr) {
        return root;
    }
    int sum = 0;
    help(root, sum);
    return root;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        TreeNode* root = readBinaryTree();
        printBinaryTree(bstToGst(root));
    }
    return 0;
}

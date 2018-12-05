#include "../leetcode.h"

using namespace std;

void flatten(TreeNode* root) {
    if (root != nullptr) {
        flatten(root->left);
        flatten(root->right);
        TreeNode* current = root;
        TreeNode* right = root->right;
        root->right = root->left;
        root->left = nullptr;
        while (current->right != nullptr) {
            current = current->right;
        }
        current->right = right;
    }
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int n = readNumber();
    for (int i = 0; i < n; ++i) {
        TreeNode* root = readBinaryTree();
        flatten(root);
        printBinaryTree(root);
    }
    return 0;
}

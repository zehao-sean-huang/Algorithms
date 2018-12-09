#include "../leetcode.h"

using namespace std;

void traverse(TreeNode* root, TreeNode* &current) {
    if (root != nullptr) {
        traverse(root->left, current);
        current->right = new TreeNode(root->val);
        current = current->right;
        traverse(root->right, current);
    }
}

TreeNode* increasingBST(TreeNode* root) {
    TreeNode* head = new TreeNode(0);
    TreeNode* current = head;
    traverse(root, current);
    return head->right;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int n = readNumber();
    for (int i = 0; i < n; ++i) {
        printBinaryTree(increasingBST(readBinaryTree()));
    }
    return 0;
}

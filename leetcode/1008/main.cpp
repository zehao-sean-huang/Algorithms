#include "../leetcode.h"

using namespace std;

void insert(int n, TreeNode* root) {
    TreeNode* node = new TreeNode(n);
    TreeNode* parent = root;
    while (root != nullptr) {
        if (n < root->val) {
            parent = root;
            root = root->left;
        } else {
            parent = root;
            root = root->right;
        }
    }
    if (n < parent->val) {
        parent->left = node;
    } else {
        parent->right = node;
    }
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    if (preorder.empty()) return nullptr;
    TreeNode* root = new TreeNode(preorder[0]);
    for (int i = 1; i < preorder.size(); ++i) {
        insert(preorder[i], root);
    }
    return root;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<int> preorder = readVector();
        printBinaryTree(bstFromPreorder(preorder));
    }
    return 0;
}

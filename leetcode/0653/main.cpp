#include "../leetcode.h"

using namespace std;

bool find(TreeNode* root, TreeNode* current, int v) {
    if (root == nullptr) return false;
    return root != current && (v == root->val || find(root->left, current, v) || 
        find(root->right, current, v));
}

bool helper(TreeNode* root, TreeNode* tree, int k) {
    if (root == nullptr) return false;
    return find(tree, root, k - root->val) || helper(root->left, tree, k) || helper(root->right, tree, k);
}

bool findTarget(TreeNode* root, int k) {
    return helper(root, root, k);
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        cout << (findTarget(readBinaryTree(), readNumber()) ? "true" : "false") << endl;
    }
    return 0;
}
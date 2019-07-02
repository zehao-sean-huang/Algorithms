#include "../leetcode.h"

using namespace std;

map<TreeNode*, int> cache;

int height(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    } 
    cache[root] = 1 + max(height(root->left), height(root->right));
    return cache[root];
}

bool isBalanced(TreeNode* root) {
    if (root == nullptr) {
        return true;
    } 
    if (!(isBalanced(root->left) && (isBalanced(root->right)))) {
        return false;
    }
    int heightGap = height(root->left) - height(root->right);
    return heightGap >= -1 && heightGap <= 1;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int n = readNumber();
    for (int i = 0; i < n; ++i) {
        cout << (isBalanced(readBinaryTree()) ? "true" : "false") << endl;
    }
    return 0;
}
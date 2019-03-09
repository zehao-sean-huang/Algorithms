#include "../leetcode.h"

using namespace std;

pair<TreeNode*, int> helper(TreeNode* root) {
    if (root == nullptr) {
        return make_pair(root, 0);
    } else {
        pair<TreeNode*, int> left = helper(root->left);
        pair<TreeNode*, int> right = helper(root->right);
        if (left.second == right.second) {
            return make_pair(root, left.second + 1);
        } else if (left.second > right.second) {
            return make_pair(left.first, left.second + 1);
        }
        return make_pair(right.first, right.second + 1);
    }
}

TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    return helper(root).first;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        printBinaryTree(subtreeWithAllDeepest(readBinaryTree()));
    }
    return 0;
}
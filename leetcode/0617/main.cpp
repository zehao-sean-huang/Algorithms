#include "../leetcode.h"

using namespace std;

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == nullptr && t2 == nullptr) {
        return nullptr;
    } else if (t1 == nullptr) {
        return t2;
    } else if (t2 == nullptr) {
        return t1;
    } else {
        TreeNode* r = new TreeNode(t1->val + t2->val);
        r->left = mergeTrees(t1->left, t2->left);
        r->right = mergeTrees(t1->right, t2->right);
        return r;
    }
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    TreeNode* t1 = readBinaryTree();
    TreeNode* t2 = readBinaryTree();
    printBinaryTree(mergeTrees(t1, t2));
    return 0;
}
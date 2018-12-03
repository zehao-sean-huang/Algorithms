#include "../leetcode.h"

using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) {
        return true;
    } else if (p == nullptr) {
        return false;
    } else if (q == nullptr) {
        return false;
    } else if (p->val != q->val) {
        return false;
    } else {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    TreeNode* p = readBinaryTree();
    TreeNode* q = readBinaryTree();
    cout << (isSameTree(p, q) ? "true" : "false") << endl;
    return 0;
}
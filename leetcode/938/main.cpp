#include "../leetcode.h"

using namespace std;

int rangeSumBST(TreeNode* root, int L, int R) {
    if (root == nullptr) {
        return 0;
    }
    int &v = root->val;
    if (v < L) {
        return rangeSumBST(root->right, L, R);
    } else if (v > R) {
        return rangeSumBST(root->left, L, R);
    } else {
        return v + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    TreeNode* root = readBinaryTree();
    int l = readNumber(), r = readNumber();
    cout << rangeSumBST(root, l, r) << endl;
    return 0;
}
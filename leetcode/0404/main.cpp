#include "../leetcode.h"

using namespace std;

int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr && isLeft) return root->val;
    return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        cout << sumOfLeftLeaves(readBinaryTree()) << endl;
    }
    return 0;
}
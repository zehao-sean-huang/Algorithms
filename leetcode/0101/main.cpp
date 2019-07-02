#include "../leetcode.h"

using namespace std;

bool isSymmetricHelper(TreeNode* first, TreeNode* second) {
    if (first == nullptr && second == nullptr) {
        return true;
    } else if (first == nullptr || second == nullptr) {
        return false;
    } else {
        return first->val == second->val
                && isSymmetricHelper(first->left, second->right)
                && isSymmetricHelper(first->right, second->left);
    }
}

bool isSymmetric(TreeNode* root) {
    return isSymmetricHelper(root, root);
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    cout << (isSymmetric(readBinaryTree()) ? "true" : "false") << endl;
    return 0;
}
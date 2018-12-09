#include "../leetcode.h"

using namespace std;

bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    } else if (root1 == nullptr || root2 == nullptr) {
        return false;
    } else if (root1->val != root2->val) { 
        return false;
    } else {
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right))
            || (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int n = readNumber();
    for (int i = 0; i < n; ++i) {
        TreeNode* root1 = readBinaryTree();
        TreeNode* root2 = readBinaryTree();
        cout << (flipEquiv(root1, root2) ? "true" : "false") << endl;
    }
    return 0;
}

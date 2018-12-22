#include "../leetcode.h"

using namespace std;

string tree2str(TreeNode* root) {
    if (root == nullptr) {
        return "";
    } else if (root->left == nullptr && root->right == nullptr) {
        return str(root->val);
    } else if (root->left == nullptr) {
        return str(root->val) + "()(" + tree2str(root->right) + ")";
    } else if (root->right == nullptr) {
        return str(root->val) + "(" + tree2str(root->left) + ")";
    } 
    return str(root->val) + "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        cout << tree2str(readBinaryTree()) << endl;
    }
    return 0;
}
#include "../leetcode.h"

using namespace std;

void explore(TreeNode* root, bool& result, int value) {
    if (root == nullptr) return;
    if (root->val != value) {
        result = false;
    }
    if (!result) return;
    explore(root->left, result, value);
    if (!result) return;
    explore(root->right, result, value);
}
bool isUnivalTree(TreeNode* root) {
    bool result = true;
    if (root == nullptr) return true;
    explore(root, result, root->val);
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        cout << (isUnivalTree(readBinaryTree()) ? "true" : "false") << endl;
    }
    return 0;
}

#include "../leetcode.h"

using namespace std;

void helper(TreeNode* root, int &k, int &ans) {
    if (root == nullptr) return;
    helper(root->left, k, ans);
    if (k-- == 1) ans = root->val;
    if (ans != INT_MIN) return;
    helper(root->right, k, ans);
}

int kthSmallest(TreeNode* root, int k) {
    int ans = INT_MIN;
    helper(root, k, ans);
    return ans;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        cout << kthSmallest(readBinaryTree(), readNumber()) << endl;
    }
    return 0;
}
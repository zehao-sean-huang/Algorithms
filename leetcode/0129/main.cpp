#include "../leetcode.h"

using namespace std;

int result = 0;

void helper(TreeNode* root, int current) {
    if (root != nullptr) {
        int next = 10 * current + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            result += next;
        } else {
            helper(root->left, next);
            helper(root->right, next);
        }
    }
}

int sumNumbers(TreeNode* root) {
    result = 0;
    helper(root, 0);
    return 0;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int n = readNumber();
    for (int i = 0; i < n; ++i) {
        result = 0;
        sumNumbers(readBinaryTree());
        cout << result << endl;
    }
    return 0;
}

#include "../leetcode.h"

using namespace std;

void helper(vector<string>& result, TreeNode* root, string current) {
    if (root == nullptr) {
        return;
    } else if (root->left == nullptr && root->right == nullptr) {
        result.push_back(current + str(root->val));
        return;
    }
    helper(result, root->left, current + str(root->val) + "->");
    helper(result, root->right, current + str(root->val) + "->");
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    helper(result, root, "");
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        TreeNode* root = readBinaryTree();
        printVector(binaryTreePaths(root));
    }
    return 0;
}
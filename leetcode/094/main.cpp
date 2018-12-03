#include "../leetcode.h"

using namespace std;

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> r;
    if (root != nullptr) {
        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);
        r.insert(r.end(), left.begin(), left.end());
        r.push_back(root->val);
        r.insert(r.end(), right.begin(), right.end());
    }
    return r;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    freopen("main.out", "w", stdout);
    #endif
    TreeNode* root = readBinaryTree();
    printVector(inorderTraversal(root));
}
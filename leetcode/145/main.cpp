#include "../leetcode.h"

using namespace std;

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root != nullptr) {
        vector<int> rl = postorderTraversal(root->left);
        vector<int> rr = postorderTraversal(root->right);
        result.insert(result.end(), rl.begin(), rl.end());
        result.insert(result.end(), rr.begin(), rr.end());
        result.push_back(root->val);
    }
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    printVector(postorderTraversal(readBinaryTree()));
    return 0;
}
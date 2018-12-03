#include "../leetcode.h"

using namespace std;

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> r;
    if (root != nullptr) {
        r.push_back(root->val);
        vector<int> rl = preorderTraversal(root->left);
        vector<int> rr = preorderTraversal(root->right);
        r.insert(r.end(), rl.begin(), rl.end());
        r.insert(r.end(), rr.begin(), rr.end());
    }
    return r;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    printVector(preorderTraversal(readBinaryTree()));
    return 0;
}
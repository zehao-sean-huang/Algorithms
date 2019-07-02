#include "../leetcode.h"

using namespace std;

vector<int> getLeaves(TreeNode* root) {
    vector<int> r;
    if (root != nullptr) {
        if (root->left == nullptr && root->right == nullptr) {
            r.push_back(root->val);
        } else {
            vector<int> rl = getLeaves(root->left);
            vector<int> rr = getLeaves(root->right);
            r.insert(r.end(), rl.begin(), rl.end());
            r.insert(r.end(), rr.begin(), rr.end());
        }
    } 
    return r;
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    return getLeaves(root1) == getLeaves(root2);
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    TreeNode* root1 = readBinaryTree();
    TreeNode* root2 = readBinaryTree();
    cout << (leafSimilar(root1, root2) ? "true" : "false") << endl;
    return 0;
}
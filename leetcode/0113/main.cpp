#include "../leetcode.h"

using namespace std;

vector<vector<int> > pathSum(TreeNode* root, int sum) {
    vector<vector<int> > result;
    if (root != nullptr) {
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == root->val) {
                vector<int> leaf;
                leaf.push_back(root->val);
                result.push_back(leaf);
            }
        } else {
            for (vector<int> r : pathSum(root->left, sum - root->val)) {
                r.insert(r.begin(), root->val);
                result.push_back(r);
            }
            for (vector<int> r : pathSum(root->right, sum - root->val)) {
                r.insert(r.begin(), root->val);
                result.push_back(r);
            }
        }
    }
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int n = readNumber();
    for (int i = 0; i < n; ++i) {
        TreeNode* root = readBinaryTree();
        int sum = readNumber();
        printGrid(pathSum(root, sum));
    }
    return 0;
}

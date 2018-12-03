#include "../leetcode.h"

using namespace std;

vector<TreeNode*> generateTreesHelper(int start, int end) {
    vector<TreeNode*> r;
    if (start > end) {
        r.push_back(nullptr);
    } else if (start == end) {
        TreeNode* t = new TreeNode(start);
        r.push_back(t);
    } else {
        vector<TreeNode*> left;
        vector<TreeNode*> right;
        for (int i = start; i <= end; ++i) {
            left = generateTreesHelper(start, i - 1);
            right = generateTreesHelper(i + 1, end);
            for (TreeNode* ln : left) {
                for (TreeNode* rn : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = ln;
                    root->right = rn;
                    r.push_back(root);
                }
            }
        }
    }
    return r;
}

vector<TreeNode*> generateTrees(int n) {
    if (n == 0) {
        vector<TreeNode*> r;
        return r;
    }
    return generateTreesHelper(1, n);
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    for (TreeNode* root : generateTrees(readNumber())) {
        printBinaryTree(root);
    }
    return 0;
}
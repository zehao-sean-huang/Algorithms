#include "../leetcode.h"

using namespace std;

TreeNode* helper(vector<int>& pre, vector<int>& post, int prei, int posti, int size) {
    if (size == 0) {
        return nullptr;
    } else {
        TreeNode* root = new TreeNode(pre[prei++]);
        if (size > 1) {
            int ls = find(post.begin() + posti, post.end(), pre[prei]) - post.begin() - posti + 1;
            root->left = helper(pre, post, prei, posti, ls);
            int rs = size - 1 - ls;
            root->right = helper(pre, post, prei + ls, posti + ls, rs);
        }
        return root;
    }
}

TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    return helper(pre, post, 0, 0, pre.size());
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int n = readNumber();
        vector<int> pre = readVector(n);
        vector<int> post = readVector(n);
        printBinaryTree(constructFromPrePost(pre, post));
    }
    return 0;
}
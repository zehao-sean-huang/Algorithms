#include "../leetcode.h"

using namespace std;

void helper(int &c, queue<TreeNode*> &q, TreeNode* n) {
    if (n->left != nullptr) {
        q.push(n->left);
        ++c;
    }
    if (n->right != nullptr) {
        q.push(n->right);
        ++c;
    }
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if (root != nullptr) {
        queue<TreeNode*> q;
        q.push(root);
        int count = 1;
        while (!q.empty()) {
            int nextCount = 0;
            TreeNode* current = q.front();
            for (int i = 1; i < count; ++i) {
                helper(nextCount, q, current);
                q.pop();
                current = q.front();
            }
            result.push_back(current->val);
            helper(nextCount, q, current);
            q.pop();
            count = nextCount;
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
        printVector(rightSideView(root));
    }
    return 0;
}

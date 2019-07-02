#include "../leetcode.h"

using namespace std;

int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> q;
    int cnt = 1, ans = 0;
    q.push(root);
    while (!q.empty()) {
        int next = 0;
        ans = q.front()->val;
        while (cnt--) {
            TreeNode* current = q.front();
            if (current->left != nullptr) {q.push(current->left); ++next;}
            if (current->right != nullptr) {q.push(current->right); ++next;}
            q.pop();
        }
        cnt = next;
    }
    return ans;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        TreeNode* root = readBinaryTree();
        cout << findBottomLeftValue(root) << endl;
    }
    return 0;
}
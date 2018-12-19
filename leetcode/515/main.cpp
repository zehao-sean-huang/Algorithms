#include "../leetcode.h"

using namespace std;

vector<int> largestValues(TreeNode* root) {
    vector<int> result;
    if (root != nullptr) {
        queue<TreeNode*> q;
        int cnt = 1, ans = INT_MIN;
        q.push(root);
        while (!q.empty()) {
            int next = 0;
            while (cnt--) {
                TreeNode* current = q.front();
                ans = max(ans, current->val);
                if (current->left != nullptr) {q.push(current->left); ++next;}
                if (current->right != nullptr) {q.push(current->right); ++next;}
                q.pop();
            }
            result.push_back(ans);
            ans = INT_MIN;
            cnt = next;
        }
    }
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        TreeNode* root = readBinaryTree();
        printVector(largestValues(root));
    }
    return 0;
}
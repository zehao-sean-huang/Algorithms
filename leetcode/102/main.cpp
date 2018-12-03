#include "../leetcode.h"

using namespace std;

vector<vector<int> > levelOrder(TreeNode* root) {
    vector<vector<int> > result;
    if (root != nullptr) {
        int count = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int nextCount = 0;
            vector<int> row;
            for (int i = 0; i < count; ++i) {
                TreeNode* current = q.front();
                row.push_back(current->val);
                if (current->left != nullptr) {
                    nextCount += 1;
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    nextCount += 1;
                    q.push(current->right);
                }
                q.pop();
            }
            count = nextCount;
            result.push_back(row);
        }
    }
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    printGrid(levelOrder(readBinaryTree()));
    return 0;
}
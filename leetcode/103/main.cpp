#include "../leetcode.h"

using namespace std;

vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    vector<vector<int> > result;
    if (root != nullptr) {
        int count = 1, level = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int nextCount = 0;
            vector<int> row;
            for (int i = 0; i < count; ++i) {
                TreeNode* current = q.front();
                if (level % 2 == 0) {
                    row.insert(row.begin(), current->val);
                } else {
                    row.insert(row.end(), current->val);
                }
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
            ++level;
        }
    }
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    printGrid(zigzagLevelOrder(readBinaryTree()));
    return 0;
}
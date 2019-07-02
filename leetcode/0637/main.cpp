#include "../leetcode.h"

using namespace std;

vector<double> averageOfLevels(TreeNode* root) {
    vector<double> result;
    if (root != nullptr) {
        int count = 1, nextCount = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            nextCount = 0;
            double sum = 0;
            for (int i = 0; i < count; ++i) {
                TreeNode* current = q.front();
                sum += current->val;
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
            result.push_back(sum / count);
            count = nextCount;
        }
    }
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    printVector(averageOfLevels(readBinaryTree()));
    return 0;
}
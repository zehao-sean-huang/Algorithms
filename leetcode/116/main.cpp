#include "../leetcode.h"

using namespace std;

void helper(TreeLinkNode* current, int &nextCount, queue<TreeLinkNode*> &q) {
    if (current->left != nullptr) {
        nextCount += 1;
        q.push(current->left);
    }
    if (current->right != nullptr) {
        nextCount += 1;
        q.push(current->right);
    }
}

void connect(TreeLinkNode *root) {
    if (root != nullptr) {
        int count = 1;
        queue<TreeLinkNode*> q;
        q.push(root);
        while (!q.empty()) {
            int nextCount = 0;
            TreeLinkNode* current = q.front();
            q.pop();
            for (int i = 1; i < count; ++i) {
                TreeLinkNode* next = q.front();
                helper(current, nextCount, q);
                current->next = next;
                current = next;
                q.pop();
            }
            helper(current, nextCount, q);
            count = nextCount;
        }
    }
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    return 0;
}

#include "../leetcode.h"

using namespace std;

vector<vector<int> > levelOrder(Node* root) {
    vector<vector<int> > result;
    if (root != nullptr) {
        int count = 1;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int nextCount = 0;
            vector<int> row;
            for (int i = 0; i < count; ++i) {
                Node* current = q.front();
                row.push_back(current->val);
                nextCount += current->children.size();
                for (Node* child : current->children) {
                    q.push(child);
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
    return 0;
}
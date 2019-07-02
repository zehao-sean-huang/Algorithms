#include "../leetcode.h"

using namespace std;

vector<int> preorder(Node* root) {
    stack<Node*> s;
    vector<int> r;
    s.push(root);
    while (!s.empty()) {
        Node* c = s.top();
        s.pop();
        if (c != nullptr) {
            r.push_back(c->val);
            vector<Node*> cd = c->children;
            for (vector<Node*>::reverse_iterator it = cd.rbegin(); it != cd.rend(); ++it) {
                s.push(*it);
            }
        }
    }
    return r;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    return 0;
}
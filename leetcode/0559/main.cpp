#include "../leetcode.h"

using namespace std;

int maxDepth(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int r = 0;
        for (Node* child : root->children) {
            r = max(r, maxDepth(child) + 1);
        }
        return r;
    }
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    return 0;
}
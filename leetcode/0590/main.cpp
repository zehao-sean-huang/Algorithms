#include "../leetcode.h"

using namespace std;

vector<int> postorder(Node* root) {
    vector<int> result;
    if (root != nullptr) {
        for (Node* child : root->children) {
            vector<int> childResult = postorder(child);
            result.insert(result.end(), childResult.begin(), childResult.end());
        }
        result.push_back(root->val);
    }
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    return 0;
}
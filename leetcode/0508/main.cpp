#include "../leetcode.h"

using namespace std;

int helper(TreeNode* root, map<int, int> &f, int &mx) {
    if (root == nullptr) {
        return 0;
    } else {
        int current = helper(root->left, f, mx) + helper(root->right, f, mx) + root->val;
        mx = max(f[current] = f.find(current) == f.end() ? 1 : f[current] + 1, mx);
        return current;
    }
}

vector<int> findFrequentTreeSum(TreeNode* root) {
    vector<int> result;
    map<int, int> f;
    int mx = 0;
    helper(root, f, mx);
    for (auto& v : f) {
        if (v.second == mx) result.push_back(v.first);
    }
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        printVector(findFrequentTreeSum(readBinaryTree()));
    }
    return 0;
}
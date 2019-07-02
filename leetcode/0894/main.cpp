#include "../leetcode.h"

using namespace std;

map<int, vector<TreeNode*> > cache;

vector<TreeNode*> allPossibleFBT(int N) {
    if (cache.find(N) == cache.end()) {
        vector<TreeNode*> result;
        if (N % 2 == 0) {
            cache[N] = result;
        } else if (N == 1) {
            result.push_back(new TreeNode(0));
            cache[N] = result;
        } else {
            for (int i = 1; i < N - 1; i += 2) {
                for (TreeNode* left : allPossibleFBT(i)) {
                    for (TreeNode* right : allPossibleFBT(N - 1 - i)) {
                        TreeNode* root = new TreeNode(0);
                        root->left = left;
                        root->right = right;
                        result.push_back(root);
                    }
                }
            }
            cache[N] = result;
        }
    }
    return cache[N];
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int n = 0;
    while (cin >> n) {
        for (TreeNode* root : allPossibleFBT(n)) {
            printBinaryTree(root);
        }
    }
    return 0;
}

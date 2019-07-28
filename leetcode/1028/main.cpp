#include "../leetcode.h"

using namespace std;

void insert(TreeNode* root, int n, int depth) {
    if (depth > 1) {
        if (root->right == nullptr) {
            insert(root->left, n, depth - 1);
        } else {
            insert(root->right, n, depth - 1);
        }
    } else { // depth == 1
        if (root->left == nullptr) {
            root->left = new TreeNode(n);
        } else {
            root->right = new TreeNode(n);
        }
    }
}

TreeNode* recoverFromPreorder(string S) {
    if (S.empty()) return nullptr;
    int depth = 0, current = 1;
    int end = current;
    while (S[end] != '-') {
        end++;
        if (end >= S.size()) {
            break;
        }
    }
    int i = stoi(S.substr(current - 1, end - current + 1));
    TreeNode* root = new TreeNode(i);
    current = end;
    while (current < S.size()) {
        while (S[current++] == '-') depth++;
        int end = current;
        while (S[end] != '-') {
            end++;
            if (end >= S.size()) {
                break;
            }
        }
        int i = stoi(S.substr(current - 1, end - current + 1));
        insert(root, i, depth);
        current = end;
        depth = 0;
    }
    return root;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s = "";
        cin >> s;
        printBinaryTree(recoverFromPreorder(s));
    }
    return 0;
}

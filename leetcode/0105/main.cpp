#include "../leetcode.h"

using namespace std;

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0 && inorder.size() == 0) {
        return nullptr;
    }
    int rootValue = preorder[0];
    TreeNode* root = new TreeNode(rootValue);
    int rootIndex = find(inorder.begin(), inorder.end(), rootValue) - inorder.begin();
    vector<int> leftInOrder(inorder.begin(), inorder.begin() + rootIndex);
    vector<int> leftPreOrder(preorder.begin() + 1, preorder.begin() + rootIndex + 1);
    vector<int> rightInOrder(inorder.begin() + rootIndex + 1, inorder.end());
    vector<int> rightPreOrder(preorder.begin() + rootIndex + 1, preorder.end());
    root->left = buildTree(leftPreOrder, leftInOrder);
    root->right = buildTree(rightPreOrder, rightInOrder);
    return root;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int n;
    while (cin >> n) {
        vector<int> preOrder = readVector(n);
        vector<int> inOrder = readVector(n);
        printBinaryTree(buildTree(preOrder, inOrder));
    }
    return 0;
}
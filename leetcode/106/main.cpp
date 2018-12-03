#include "../leetcode.h"

using namespace std;

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.size() == 0 && postorder.size() == 0) {
        return nullptr;
    }
    int rootValue = postorder[postorder.size() - 1];
    TreeNode* root = new TreeNode(rootValue);
    int rootIndex = find(inorder.begin(), inorder.end(), rootValue) - inorder.begin();
    vector<int> leftInOrder(inorder.begin(), inorder.begin() + rootIndex);
    vector<int> leftPostOrder(postorder.begin(), postorder.begin() + rootIndex);
    vector<int> rightInOrder(inorder.begin() + rootIndex + 1, inorder.end());
    vector<int> rightPostOrder(postorder.begin() + rootIndex, postorder.end() - 1);
    root->left = buildTree(leftInOrder, leftPostOrder);
    root->right = buildTree(rightInOrder, rightPostOrder);
    return root;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int n;
    while (cin >> n) {
        vector<int> inOrder = readVector(n);
        vector<int> postOrder = readVector(n);
        printBinaryTree(buildTree(inOrder, postOrder));
    }
    return 0;
}
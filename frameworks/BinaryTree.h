#include <iostream>
using namespace std;
class BinaryTree {
    private: 
    struct BinaryTreeNode {
        int data;
        BinaryTreeNode* left;
        BinaryTreeNode* right;
        BinaryTreeNode(int d = 0, BinaryTreeNode* l = nullptr, BinaryTreeNode* r = nullptr);
        int nChildren() const;
        bool isLeave() const;
    };
    BinaryTreeNode* root;
    void heightHelper(BinaryTreeNode* head, int &result, int depth) const;
    int nLeftNodesHelper(BinaryTreeNode* head) const;
    int nRightNodesHelper(BinaryTreeNode* head) const;
    int nNodesHelper(BinaryTreeNode* head) const;
    int isBalancedHelper(BinaryTreeNode* head, bool &result) const;
    void removeLeavesHelper(BinaryTreeNode* head);
    void completeToLevelHelper(BinaryTreeNode* &head, int level, int target, int value);
    void tightenHelper(BinaryTreeNode* &head);
    void removeTree(BinaryTreeNode* &head);
    void limitPathSumHelper(BinaryTreeNode* &head, int sum);
    void swapChildrenAtLevelHelper(BinaryTreeNode* &head, int target, int level);
    public:
    BinaryTree(BinaryTreeNode* r);
    int height() const;
    int nLeftNodes() const;
    int nRightNodes() const;
    int nNodes() const;
    bool isBalanced() const;
    void removeLeaves();
    void completeToLevel(int level, int value);
    void tighten();
    void limitPathSum(int sum);
    void swapChildrenAtLevel(int level);
    void removeMatchingLeaves(BinaryTree* &anotherTree);
};
#include "BinaryTree.h"
#include <iostream>
#include <cstdio>
using namespace std;

BinaryTree::BinaryTreeNode::BinaryTreeNode(int d, BinaryTreeNode* l, BinaryTreeNode* r) {
    data = 0;
    left = l;
    right = r;
}

int BinaryTree::BinaryTreeNode::nChildren() const {
    if (isLeave()) return 0;
    int result = 0;
    if (left != nullptr) {
        ++result;
    }
    if (right != nullptr) {
        ++result;
    }
    return result;
}

void BinaryTree::heightHelper(BinaryTreeNode* head, int &result, int depth) const {
    if (head == nullptr) {
        if (depth > result) {
            result = depth;
        }
        return;
    }
    heightHelper(head -> left, result, depth + 1);
    heightHelper(head -> right, result, depth + 1);
}

int BinaryTree::height() const {
    int result = 0;
    heightHelper(root, result, 0);
    return result;
}

int BinaryTree::nLeftNodesHelper(BinaryTreeNode* head) const {
    if (head == nullptr) return 0;
    int temp = 0;
    if (head -> left != nullptr) {
        temp += 1 + nLeftNodesHelper(head -> left);
    }
    if (head -> right != nullptr) {
        temp += nLeftNodesHelper(head -> right);
    }
    return temp;
}

int BinaryTree::nLeftNodes() const {
    return nLeftNodesHelper(root);
}

int BinaryTree::nRightNodesHelper(BinaryTreeNode* head) const {
    if (head == nullptr) return 0;
    int temp = 0;
    if (head -> left != nullptr) {
        temp += nRightNodesHelper(head -> left);
    }
    if (head -> right != nullptr) {
        temp += 1 + nRightNodesHelper(head -> right);
    }
    return temp;
}

int BinaryTree::nRightNodes() const {
    return nRightNodesHelper(root);
}

int BinaryTree::nNodesHelper(BinaryTreeNode* head) const {
    if (head == nullptr) return 0;
    int temp = 0;
    if (head -> left != nullptr) {
        temp += nNodesHelper(head -> left) + 1;
    }
    if (head -> right != nullptr) {
        temp += nNodesHelper(head -> right) + 1;
    }
    return temp;
}

int BinaryTree::nNodes() const {
    return nNodesHelper(root);
}

int BinaryTree::isBalancedHelper(BinaryTreeNode* head, bool &result) const {
    if (head == nullptr) {
        return 0;
    }
    int leftHeight = isBalancedHelper(head -> left, result);
    int rightHeight = isBalancedHelper(head -> right, result);
    if (rightHeight - leftHeight < -1 || rightHeight - leftHeight > 1) {
        result = false;
    }
    return leftHeight > rightHeight ? (leftHeight + 1):(rightHeight + 1);
}

bool BinaryTree::isBalanced() const {
    if (root == nullptr) return true;
    bool result = true;
    isBalancedHelper(root, result);
    return result;
}

bool BinaryTree::BinaryTreeNode::isLeave() const {
    if (left != nullptr) return false;
    if (right != nullptr) return false;
    return true;
}

void BinaryTree::removeLeavesHelper(BinaryTreeNode* head) {
    if (head -> left != nullptr) {
        if (head -> left -> isLeave()) {
            delete head -> left;
            head -> left = nullptr;
        }
        else {
            removeLeavesHelper(head -> left);
        }
    }
    if (head -> right != nullptr) {
        if (head -> right -> isLeave()) {
            delete head -> right;
            head -> right = nullptr;
        }
        else {
            removeLeavesHelper(head -> right);
        }
    }
}

void BinaryTree::removeLeaves() {
    if (root == nullptr) return;
    if (root -> isLeave()) {
        delete root;
        root = nullptr;
    }
    else removeLeavesHelper(root);
}

void BinaryTree::completeToLevelHelper(BinaryTreeNode* &head, int level, int target, int value) {
    if (level == target) {
        if (head == nullptr) {
            head = new BinaryTreeNode(value, nullptr, nullptr);
        }
        return;
    }
    if (head == nullptr) {
        head = new BinaryTreeNode(value ,nullptr, nullptr);
    }
    completeToLevelHelper(head -> left, level + 1, target, value);
    completeToLevelHelper(head -> right, level + 1, target, value);
}

void BinaryTree::completeToLevel(int level, int value) {
    if (level < 1) throw level;
    completeToLevelHelper(root, 1, level, value);
}

void BinaryTree::tightenHelper(BinaryTreeNode* &head) {
    if (head == nullptr) return;
    if (head -> nChildren() == 1) {
        BinaryTreeNode* temp = head;
        if (head -> right == nullptr) {
            head = head -> left;
        }
        else {
            head = head -> right;
        }
        delete temp;
        tightenHelper(head);
    }
    else { 
        tightenHelper(head -> left);
        tightenHelper(head -> right);
    }
}

void BinaryTree::tighten() {
    BinaryTreeNode* &head = root;
    tightenHelper(head);
}

void BinaryTree::removeTree(BinaryTreeNode* &head) {
    if (head == nullptr) {
        return;
    }
    removeTree(head -> left);
    removeTree(head -> right);
    delete head;
    head = nullptr;
}

void BinaryTree::limitPathSumHelper(BinaryTreeNode* &head, int sum) {
    if (head == nullptr) return;
    if (head -> data > sum) {
        removeTree(head);
        return;
    }
    limitPathSumHelper(head -> left, sum - head -> data);
    limitPathSumHelper(head -> right, sum - head -> data);
}

void BinaryTree::limitPathSum(int sum) {
    BinaryTreeNode* &head = root;
    limitPathSumHelper(root, sum);
}

void BinaryTree::swapChildrenAtLevelHelper(BinaryTreeNode* &head, int target, int level) {
    if (head == nullptr) return;
    if (target == level) {
        BinaryTreeNode* temp = head -> left;
        head -> left = head -> right;
        head -> right = temp;
    }
    swapChildrenAtLevelHelper(head -> left, target, level + 1);
    swapChildrenAtLevelHelper(head -> right, target, level + 1);
}

void BinaryTree::swapChildrenAtLevel(int level) {
    if (level <= 0) throw level;
}

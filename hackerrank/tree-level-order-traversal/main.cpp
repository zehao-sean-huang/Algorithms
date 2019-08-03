#include <bits/stdc++.h>

using namespace std;
	
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
*/

    void levelOrder(Node * root) {
        if (root == nullptr) return;
        queue<Node*> q;
        int count = 1;
        q.push(root);
        while (!q.empty()) {
            int nextCount = 0;
            for (int i = 0; i < count; ++i) {
                Node* current = q.front();
                if (current->left != nullptr) {
                    q.push(current->left);
                    nextCount += 1;
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                    nextCount += 1;
                }
                cout << current->data << " ";
                q.pop();
                count = nextCount;
            }
        }
        cout << endl;
        return;
    }

}; //End of Solution

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.levelOrder(root);

    return 0;
}


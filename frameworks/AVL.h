#include <iostream>

class AVL {
    private:
    struct node {
        int data;
        node* left;
        node* right;
        int height() const;
    };
    node* root;
    int max(int a, int b) const;
    public:
    void insert(int value);
};
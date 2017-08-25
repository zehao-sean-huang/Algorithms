#include <set>
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;
struct node {
    int data;
    node* left;
    node* right;
    node(int td = 0, node* tl = NULL, node* tr = NULL) {
        data = td;
        left = tl;
        right = tr;
    }
};
int N = 0;
node* head = NULL;
void insert(node* &head, int value);
void print(node* head);
int main() {
    scanf("%d",&N);
    for (int i = 0; i < N; ++i) {
        int temp;
        scanf("%d",&temp);
        insert(head,temp);
    }
    print(head);
    printf("\n");
}
void print(node* head) {
    if (head -> left == NULL && head -> right == NULL) {
        printf("%d ", head -> data);
        return;
    }
    if (head -> left != NULL) {
        print(head -> left);
    }
    printf("%d ", head -> data);
    if (head -> right != NULL) {
        print(head -> right);
    }
}
void insert(node* &head, int value) {
    if (head == NULL) {
        head = new node(value);
        return;
    }
    if (value > head -> data) {
        insert(head -> right, value);
    }
    else {
        insert(head -> left, value);
    }
}
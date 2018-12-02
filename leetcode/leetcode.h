#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

void printVector(vector<int> v) {
    if (v.empty()) {
        cout << "<empty vector>" << endl;
    } else {
        for (int i : v) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void printGrid(vector<vector<int> > g) {
    for (vector<int> &v : g) {
        printVector(v);
    }
}

void printPair(pair<int, int> p) {
    cout << p.first << " " << p.second << endl;
}

void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int readNumber() {
    int result;
    cin >> result;
    return result;
}

vector<int> readVector(int size) {
    vector<int> result;
    for (int i = 1; i <= size; ++i) {
        int temp;
        cin >> temp;
        result.push_back(temp);
    }
    return result;
}

vector<vector<int> > readGrid(int m, int n) {
    vector<vector<int> > result;
    for (int i = 1; i <= m; ++i) {
        result.push_back(readVector(n));
    }
    return result;
}

ListNode* readLinkedList(int n) {
    ListNode* head = new ListNode(-1);
    cin >> head->val;
    ListNode* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new ListNode(-1);
        current = current->next;
        cin >> current->val;
    }
    return head;
}

#include "../leetcode.h"

using namespace std;

struct Head {
    ListNode* node;
    
    Head(ListNode* n) {
        node = n;
    }
};

struct Comp {
    bool operator() (const Head& a, const Head& b) {
        return a.node->val > b.node->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* head = new ListNode(-1);
    ListNode* result = head;
    priority_queue<Head, vector<Head>, Comp> pq;
    for (ListNode* list : lists) {
        if (list != nullptr) {
            pq.push(Head(list));
        }
    }
    while (!pq.empty()) {
        Head current = pq.top();
        cout << current.node->val << endl;
        pq.pop();
        result->next = current.node;
        result = result->next;
        if (current.node->next != nullptr) {
            pq.push(Head(current.node->next));
        }
        current.node->next = nullptr;
    }
    return head->next;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int n = readNumber();
        vector<ListNode*> lists;
        for (int j = 0; j < n; ++j) {
            lists.push_back(readLinkedList(readNumber()));
        }
        printLinkedList(mergeKLists(lists));
    }
    return 0;
}

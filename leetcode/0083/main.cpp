#include "../leetcode.h"

using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) return head;
    if (head->next == nullptr) return head;
    ListNode* n = head->next;
    while (n->val == head->val) {
        head->next = n->next;
        delete n;
        n = head->next;
        if (n == nullptr) break;
    }
    head->next = deleteDuplicates(n);
    return head;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        ListNode* l = readLinkedList();
        printLinkedList(deleteDuplicates(l));
    }
    return 0;
}

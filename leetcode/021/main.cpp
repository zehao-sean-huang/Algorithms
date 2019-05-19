#include "../leetcode.h"

using namespace std;

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
        return l2;
    } else if (l2 == nullptr) {
        return l1;
    }
    if (l1->val >= l2->val) {
        ListNode* result = new ListNode(l2->val);
        result->next = mergeTwoLists(l1, l2->next);
        return result;
    } else {
        ListNode* result = new ListNode(l1->val);
        result->next = mergeTwoLists(l1->next, l2);
        return result;
    }
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        ListNode* lst1 = readLinkedList(readNumber());
        ListNode* lst2 = readLinkedList(readNumber());
        printLinkedList(mergeTwoLists(lst1, lst2));
    }
    return 0;
}

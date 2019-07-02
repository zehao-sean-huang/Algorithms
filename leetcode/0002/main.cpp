#include "../leetcode.h"

using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode *p = l1, *q = l2, *curr = dummyHead;
    int carry = 0;
    while (p != nullptr || q != nullptr) {
        int x = (p != nullptr) ? p->val : 0;
        int y = (q != nullptr) ? q->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
        if (p != nullptr) p = p->next;
        if (q != nullptr) q = q->next;
    }
    if (carry > 0) {
        curr->next = new ListNode(carry);
    }
    return dummyHead->next;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    ListNode* l1 = readLinkedList(3);
    ListNode* l2 = readLinkedList(3);
    printLinkedList(addTwoNumbers(l1, l2));
    return 0;
}
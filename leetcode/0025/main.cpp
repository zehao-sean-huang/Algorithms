#include "../leetcode.h"

using namespace std;

ListNode* reverseList(ListNode* head) {
    if (head == nullptr) {
        return head;
    } else if (head->next == nullptr) {
        return head;
    }
    ListNode* next = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return next;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr) {
        return nullptr;
    }
    ListNode* current = head;
    int i = k;
    while (--i && current != nullptr) {
        current = current->next;
    }
    if (current == nullptr) {
        return head;
    } else {
        ListNode* next = reverseKGroup(current->next, k);
        current->next = nullptr;
        ListNode* result = reverseList(head);
        head->next = next;
        return result;
    }
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        printLinkedList(reverseKGroup(readLinkedList(), readNumber()));
    }
    return 0;
}

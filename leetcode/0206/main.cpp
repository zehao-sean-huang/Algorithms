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

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        printLinkedList(reverseList(readLinkedList()));
    }
    return 0;
}

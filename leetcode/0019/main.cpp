#include "../leetcode.h"

using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* result = head;
    int index = 0;
    while (current != nullptr) {
        current = current->next;
        if (++index > n) {
            prev = result;
            result = result->next;
        }
    }
    if (prev == nullptr) {
        head = head->next;
    } else {
        prev->next = result->next;
    }
    return head;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        ListNode* head = readLinkedList(readNumber());
        printLinkedList(removeNthFromEnd(head, readNumber()));
    }
    return 0;
}

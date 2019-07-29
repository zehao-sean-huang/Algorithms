#include "../leetcode.h"

using namespace std;

ListNode* middleNode(ListNode* head) {
    ListNode* current = head;
    ListNode* result = head;
    int index = 0;
    while (current != nullptr) {
        current = current->next;
        if (index++ % 2) {
            result = result->next;
        }
    }
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        ListNode* head = readLinkedList(readNumber());
        printLinkedList(middleNode(head));
    }
    return 0;
}

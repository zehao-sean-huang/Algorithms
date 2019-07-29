#include "../leetcode.h"

using namespace std;

ListNode* swapPairs(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    } else if (head->next == nullptr) {
        return head;
    } else {
        ListNode* n = head->next->next;
        ListNode* result = head->next;
        head->next->next = head;
        head->next = swapPairs(n);
        return result;
    }
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        printLinkedList(swapPairs(readLinkedList(readNumber())));
    }
    return 0;
}

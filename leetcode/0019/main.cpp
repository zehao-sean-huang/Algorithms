#include "../leetcode.h"

using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n) {
    
    return nullptr;
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

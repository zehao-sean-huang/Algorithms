#include "../leetcode.h"

using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) return head;
    if (head->next == nullptr) return head;
    if (head->val == head->next->val) {
        while (head->next != nullptr) {
            if (head->val == head->next->val) {
                ListNode* prev = head;
                head = head->next;
                delete prev;
            } else {
                break;
            }
        }
        ListNode* prev = head;
        head = head->next;
        delete prev;
        return deleteDuplicates(head);
    } 
    head->next = deleteDuplicates(head->next);
    return head;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        ListNode* h = readLinkedList();
        printLinkedList(deleteDuplicates(h));
    }
    return 0;
}

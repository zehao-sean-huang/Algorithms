#include "../leetcode.h"

using namespace std;

ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || k == 0) return head;
    if (head->next == nullptr) return head;
    ListNode* tail = head->next, *prev = head;
    int n = 1;
    while (tail != nullptr) {
        n++;
        tail = tail->next;
        prev = prev->next;
    }
    k %= n;
    if (k == 0) return head;
    int i = 0;
    ListNode* curr = head, *point = head;
    while (curr != nullptr) {
        curr = curr->next;
        if (i > k) {
            point = point->next;
        }
        i++;
    }
    prev->next = head;
    head = point->next;
    point->next = nullptr;
    return head;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        ListNode* h = readLinkedList();
        int k = readNumber();
        printLinkedList(rotateRight(h, k));
    }
    return 0;
}

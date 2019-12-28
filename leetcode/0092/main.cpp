#include "../leetcode.h"

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<vector<string>> vvs;
typedef vector<string> vs;
typedef pair<int, int> pii;
#define ll long long
#define l long
#define fi(x) x.first
#define se(x) x.second
#define be(x) x.begin()
#define en(x) x.end()
#define str(x) string(to_string(x))
#define ord(x) int(x - '0')
#define chr(x) char(x + '0')
#define len(x) x.size()

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (m > 1) {
        ListNode* next = reverseBetween(head->next, m - 1, n - 1);
        head->next = next;
    } else if (n != 1) {
        ListNode* next = reverseBetween(head->next, 1, n - 1);
        ListNode* current = next;
        for (int i = 1; i < n - 1; ++i) {
            current = current->next;
        }
        head->next = current->next;
        current->next = head;
        head = next;
    }
    return head;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int m = readNumber();
        int n = readNumber();
        ListNode* list = readLinkedList();
        printLinkedList(reverseBetween(list, m, n));
    }
    return 0;
}

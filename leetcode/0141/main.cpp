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

bool hasCycle(ListNode *head) {
    set<ListNode*> appeared;
    bool result = false;
    while (head != NULL) {
        if (appeared.find(head) != appeared.end()) {
            result = true;
            break;
        } else {
            appeared.insert(head);
            head = head->next;
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
        // test case
        ListNode* head = readLinkedList();
        cout << (hasCycle(head) ? "true" : "false") << endl;
    }
    return 0;
}

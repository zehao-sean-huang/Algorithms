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

struct StackNode {
    int number;
    int minimum;
    StackNode(int n) {
        number = n;
        minimum = n;
    }
};

class MinStack {
public:
    /** initialize your data structure here. */
    stack<StackNode> s;
    
    MinStack() {
        ;
    }
    
    void push(int x) {
        StackNode node(x);
        if (!s.empty()) {
            node.minimum = min(x, s.top().minimum);
        }
        s.push(node);
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().number;
    }
    
    int getMin() {
        return s.top().minimum;
    }
};

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        ; // test case
    }
    return 0;
}

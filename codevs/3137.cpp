#include <stack> 
#include <iostream>
using namespace std;
int cnt;
stack<int> s;
int main() {
    cin >> cnt;
    for (int i = 1; i <= cnt; ++i) {
        int action; 
        cin >> action;
        if (action == 1) {
            int n;
            cin >> n;
            s.push(n);
        }
        else {
            s.pop();
        }
    }
    if (s.empty()) {
        cout << "impossible!" << endl;
    }
    else {
        cout << s.top() << endl;
    }
    return 0;
}
#include <stack> 
#include <iostream>
using namespace std;
int cnt;
stack<int> s;
void something(stack<int> &s, int &cnt) {
    for (int i = 1; i <= cnt; ++i) {
        int action; 
        cin >> action;
        if (action == 1) {
            int n;
            cin >> n;
            s.push(n);
        }
        else {
            if (!s.empty()) {
                s.pop();
            }
            else {
                cout << "impossible!" << endl;
                return;
            }
        }
    }
    if (s.empty()) {
        cout << "impossible!" << endl;
    }
    else {
        cout << s.top() << endl;
    }
    return; 
}
int main() {
    cin >> cnt;
    something(s,cnt);
}
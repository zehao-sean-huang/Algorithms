#include <stack> 
#include <iostream>
using namespace std;
int cnt;
stack<int> s;
void something(stack<int> &s, int &cnt) {
    for (int i = 1; i <= cnt; ++i) {
        int action; 
        cin >> action;
        switch (action) {
            case 1: {
                cin >> action;
                s.push(action);
                break;
            }
            case 2: {
                s.pop();
                break;
            }
            case 3: {
                cout << s.top() << endl;
                break;
            }
        }
    }
    return; 
}
int main() {
    cin >> cnt;
    something(s,cnt);
}

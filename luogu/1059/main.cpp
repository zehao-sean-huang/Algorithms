#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int n;
int a[110];
set<int> b;

int main () {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b.insert(a[i]);
    }
    cout << b.size() << endl;
    int i = 1;
    for (set<int>::iterator it = b.begin(); it != b.end(); ++it) {
        if (b.size() - i) {
            cout << *it << " ";
            ++i;
        } else {
            cout << *it << endl;
        }
    }
    cout << endl;
    return 0;
}
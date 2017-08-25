#include <iostream>
#include <string>
using namespace std;
int main() {
    string a;
    string b;
    cin >> a >> b;
    for (int i = 0; i < int(a.size()) - int(b.size()) + 1; ++i) {
        if (b == a.substr(i, b.size())) {
            cout << i + 1<< endl;
            return 0;
        }
    }
    return 0;
}
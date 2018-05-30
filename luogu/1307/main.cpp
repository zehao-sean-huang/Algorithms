#include <iostream>
#include <string>

using namespace std;

string s;

int main() {
    cin >> s;
    bool negative = (s[0] == '-');
    if (negative) {
        s = s.substr(1);
    }
    while (s[s.size() - 1] == '0') {
        s = s.substr(0, s.size() - 1);
    }
    if (!s.size()) {
        cout << 0 << endl;
    } else {
        if (negative) {
            cout << "-";
        }
        for (int i = s.size() - 1; i >= 0; --i) {
            cout << s[i];
        }
    }
    cout << endl;
    return 0;
}
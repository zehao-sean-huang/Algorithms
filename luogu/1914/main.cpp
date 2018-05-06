#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        cout << ((s[i] + n) > 122 ? char(s[i] + n - 26) : char(s[i] + n));
    }
    cout << endl;
    return 0;
}

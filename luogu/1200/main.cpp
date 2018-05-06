#include <iostream>
#include <string>

using namespace std;

int process(string s) {
    int result = 1;
    for (int i = 0; i < s.size(); ++i) {
        result *= (s[i] - 64);
    }
    return result % 47;
}

int main() {
    string a, b;
    cin >> a >> b;
    if (process(a) == process(b)) {
        cout << "GO" << endl;
    } else {
        cout << "STAY" << endl;
    }
    return 0;
}

#include "../leetcode.h"

using namespace std;

string addBinary(string a, string b) {
    int m = a.size(), n = b.size(), l = min(m, n), c = 0;
    string ans;
    for (int i = 0; i < l; ++i) {
        int r = a[m - i - 1] - '0' + b[n - i - 1] - '0' + c;
        c = r / 2;
        r = r % 2;
        ans = char(r + '0') + ans;
    }
    for (int i = l; i < m; ++i) {
        int r = a[m - i - 1] - '0' + c;
        c = r / 2;
        r = r % 2;
        ans = char(r + '0') + ans;
    }
    for (int i = l; i < n; ++i) {
        int r = b[n - i - 1] - '0' + c;
        c = r / 2;
        r = r % 2;
        ans = char(r + '0') + ans;
    }
    if (c) {
        ans = '1' + ans;
    }
    return ans;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string a, b;
        cin >> a >> b;
        cout << addBinary(a, b) << endl;
    }
    return 0;
}

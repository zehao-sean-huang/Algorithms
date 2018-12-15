#include "../euler.h"

using namespace std;

bool isPalindrom(string s) {
    int m = s.size();
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[m - 1 - i]) {
            return false;
        }
    }
    return true;
}

bool judge(int n) {
    string base10 = str(n);
    string base2 = "";
    while (n != 0) {
        int b = n % 2;
        n = n / 2;
        base2 += char(b + '0');
    }
    return isPalindrom(base10) && isPalindrom(base2);
}

int ans = 0;

int main() {
    int limit = 1000000;
    for (int i = 1; i < limit; ++i) {
        if (judge(i)) {
            cout << i << endl;
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}

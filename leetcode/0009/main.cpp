#include "../leetcode.h"

using namespace std;

bool isPalindrome(int x) {
    string number = string(to_string(x));
    int n = number.size();
    if (n == 1) {
        return true;
    }
    for (int i = 0; i < n / 2; ++i) {
        // i = 0, n = 4, j = n - 1 - i
        if (number[i] != number[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int x = 0;
    while (cin >> x) {
        cout << x << " " << (isPalindrome(x) ? "true" : "false") << endl;
    }
    return 0;
}
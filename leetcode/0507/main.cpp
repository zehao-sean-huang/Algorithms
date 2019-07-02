#include "../leetcode.h"

bool checkPerfectNumber(int num) {
    if (num == 0) return true;
    if (num == 1) return false;
    int sum = 0;
    for (int i = 1; i <= int(sqrt(num)); ++i) {
        if (num % i == 0) {
            sum += (i + num / i);
        }
        if (sum == i * i) {
            sum -= i;
        }
    }
    return sum == 2 * num;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int num = 0;
    while (cin >> num) {
        cout << num << " " << (checkPerfectNumber(num) ? "true" : "false") << endl;
    }
    return 0;
}
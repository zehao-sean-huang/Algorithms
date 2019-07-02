#include "../leetcode.h"

using namespace std;

void helper(string &result, string l, string m, string r, int &num, int scale) {
    num %= (scale * 10);
    int n = num / scale;
    if (n == 9) {
        result += l + r;
        n = 0;
    } else if (n >= 5) {
        result += m;
        n -= 5;
    } else if (n == 4) {
        result += l + m;
        n = 0;
    }
    while (n--) {
        result += l;
    }
}

string intToRoman(int num) {
    string result = "";
    helper(result, "M", "!", "!", num, 1000);
    helper(result, "C", "D", "M", num, 100);
    helper(result, "X", "L", "C", num, 10);
    helper(result, "I", "V", "X", num, 1);
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int number = 0;
    while (cin >> number) {
        cout << number << " " << intToRoman(number) << endl;
    }
    return 0;
}
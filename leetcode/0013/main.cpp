#include "../leetcode.h"

using namespace std;

int romanToInt(string s) {
    map<char, int> dict;
    dict['I'] = 1;
    dict['V'] = 5;
    dict['X'] = 10;
    dict['L'] = 50;
    dict['C'] = 100;
    dict['D'] = 500;
    dict['M'] = 1000;
    int ans = 0;
    char p = '0';
    for (char c : s) {
        ans += dict[c];
        if ((p == 'I' && (c == 'V' || c == 'X')) 
            || (p == 'X' && (c == 'L' || c == 'C')) 
            || (p == 'C' && (c == 'D' || c == 'M'))) {
            ans -= 2 * dict[p];
        }
        p = c;
    }
    return ans;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    string roman;
    while (cin >> roman) {
        cout << roman << " " << romanToInt(roman) << endl;
    }
    return 0;
}
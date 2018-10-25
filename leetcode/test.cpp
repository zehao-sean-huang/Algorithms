#include "solutions.cpp"

using namespace std;

void p44(Solution &solutions) {
    cout << solutions.isMatchWildcard("aa", "a") << endl;
    cout << solutions.isMatchWildcard("aa", "*") << endl;
    cout << solutions.isMatchWildcard("cb", "?a") << endl;
    cout << solutions.isMatchWildcard("adceb", "*a*b") << endl;
    cout << solutions.isMatchWildcard("acdcb", "a*c?b") << endl;
}

void p87(Solution &s) {
    cout << s.isScramble("great", "rgeat") << endl; // true
    cout << s.isScramble("great", "rgtae") << endl; // true
    cout << s.isScramble("abcde", "caebd") << endl; // false
}

void p91(Solution &s) {
    cout << s.numDecodings("12") << endl; // 2
    cout << s.numDecodings("226") << endl; // 3
    cout << s.numDecodings("0") << endl; // 0
    cout << s.numDecodings("10") << endl; // 1
}

int main() {
    Solution solutions = Solution();
    // p44(solutions);
    // p87(solutions);
    // p91(solutions);
    return 0;
}
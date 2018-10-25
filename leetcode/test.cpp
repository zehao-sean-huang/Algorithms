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

int main() {
    Solution solutions = Solution();
    // p44(solutions);
    p87(solutions);
    return 0;
}
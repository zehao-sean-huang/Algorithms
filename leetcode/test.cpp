#include "solutions.cpp"

using namespace std;

void p3(Solution &s) {
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl; // 3
    cout << s.lengthOfLongestSubstring("bbbbb") << endl; // 1
    cout << s.lengthOfLongestSubstring("pwwkew") << endl; // 3
}

void p9(Solution &s) {
    cout << s.isPalindrome(121) << endl; // true
    cout << s.isPalindrome(-121) << endl; // false
    cout << s.isPalindrome(10) << endl; // false
}

void p44(Solution &s) {
    cout << s.isMatchWildcard("aa", "a") << endl;
    cout << s.isMatchWildcard("aa", "*") << endl;
    cout << s.isMatchWildcard("cb", "?a") << endl;
    cout << s.isMatchWildcard("adceb", "*a*b") << endl;
    cout << s.isMatchWildcard("acdcb", "a*c?b") << endl;
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

void p96(Solution &s) {
    cout << s.numTrees(1) << endl; // 1
    cout << s.numTrees(2) << endl; // 2
    cout << s.numTrees(3) << endl; // 5
    cout << s.numTrees(4) << endl; // 14
}

void p97(Solution &s) {
    cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << s.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
}

void p115(Solution &s) {
    cout << s.numDistinct("rabbbit", "rabbit") << endl; // 3
    cout << s.numDistinct("babgbag", "bag") << endl; // 5
}

int main() {
    Solution solutions = Solution();
    p3(solutions);
    // p44(solutions);
    // p87(solutions);
    // p91(solutions);
    // p96(solutions);
    // p97(solutions);
    // p115(solutions);
    return 0;
}
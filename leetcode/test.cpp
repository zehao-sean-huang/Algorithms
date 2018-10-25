#include "solutions.cpp"

using namespace std;

void p44(Solution &solutions) {
    cout << solutions.isMatchWildcard("aa", "a") << endl;
    cout << solutions.isMatchWildcard("aa", "*") << endl;
    cout << solutions.isMatchWildcard("cb", "?a") << endl;
    cout << solutions.isMatchWildcard("adceb", "*a*b") << endl;
    cout << solutions.isMatchWildcard("acdcb", "a*c?b") << endl;
}

int main() {
    Solution solutions = Solution();
    p44(solutions);
    return 0;
}
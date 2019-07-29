#include "../leetcode.h"

using namespace std;

void helper(string s, int open, int closed, vector<string>& result) {
    if (open == 0 && closed == 0) {
        result.push_back(s);
    } else {
        if (open > 0 && closed >= open) {
            helper(s + '(', open - 1, closed, result);
        }
        if (closed > 0 && closed > open) {
            helper(s + ')', open, closed - 1, result);
        }
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    helper("", n, n, result);
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        printVector(generateParenthesis(readNumber()));
    }
    return 0;
}

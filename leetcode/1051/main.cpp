#include "../leetcode.h"

using namespace std;

int heightChecker(vector<int>& heights) {
    int result = 0;
    vector<int> s(heights.begin(), heights.end());
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size(); ++i) {
        if (heights[i] != s[i]) result += 1;
    }    
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<int> v = readVector();
        cout << heightChecker(v) << endl;
    }
    return 0;
}

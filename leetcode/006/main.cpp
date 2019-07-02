#include "../leetcode.h"

using namespace std;

string convert(string s, int numRows) {
    if (numRows == 1) return s;
    string result = "";
    int group = numRows * 2 - 2, size = s.size();
    // first row
    for (int i = 0; i < size; i += group) result += s[i];
    // middle rows
    for (int r = 1; r < numRows - 1; ++r) {
        int i = r, step = i * 2;
        while (i < size) {
            result += s[i];
            step = group - step;
            i += step;
        }
    }
    // last row
    for (int i = numRows - 1; i < size; i += group) result += s[i];
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s = "";
        int num = 0;
        cin >> s >> num;
        cout << convert(s, num) << endl;
    }
    return 0;
}

#include "../leetcode.h"

using namespace std;

string countAndSay(int n) {
    int i = 1;
    string ans = "1";
    while (i < n) {
        string ns = "";
        int j = 0;
        while (j < ans.size()) {
            int k = j;
            while (ans[k] == ans[j]) {
                k += 1;
                if (k == ans.size()) break;
            }
            ns += (k - j + '0');
            ns += (ans[j]);
            j = k;
        }
        ans = ns;
        i += 1;
    }
    return ans;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        cout << countAndSay(readNumber()) << endl;
    }
    return 0;
}

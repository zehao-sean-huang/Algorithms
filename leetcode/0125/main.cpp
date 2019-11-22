#include "../leetcode.h"

using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<vector<string>> vvs;
typedef vector<string> vs;
typedef pair<int, int> pii;
#define ll long long
#define l long
#define fi(x) x.first
#define se(x) x.second
#define be(x) x.begin()
#define en(x) x.end()
#define str(x) string(to_string(x))
#define ord(x) int(x - '0')
#define chr(x) char(x + '0')
#define len(x) x.size()

bool isPalindrome(string s) {
    // two pointers
    int n = s.size();
    int i = 0, j = n - 1;
    while (i <= j) {
        while (i < n) {
            if (isalnum(s[i])) break;
            i++;
        }
        while (j >= 0) {
            if (isalnum(s[j])) break;
            j--;
        }
        if (i >= n || j < 0 || i > j) break;
        if (tolower(s[i]) != tolower(s[j])) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s;
        while (s.empty()) getline(cin, s);
        cout << (isPalindrome(s) ? "true" : "false") << " " << s << endl;
    }
    return 0;
}

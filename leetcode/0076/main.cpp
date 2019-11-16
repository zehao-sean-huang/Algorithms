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

bool eligible(int* target, int* current) {
    for (int i = 0; i < 26; ++i) {
        if (current[i] < target[i]) {
            return false;
        }
    }
    return true;
}

string minWindow(string s, string t) {
    int target[30];
    int current[30];
    memset(target, 0, sizeof(target));
    memset(current, 0, sizeof(current));
    for (char &c : t) target[tolower(c) - 'a']++;
    int i = 0, j = 0; // sliding window [i,j)
    int n = s.size(), cur = INT_MAX;
    string result = "";
    while (j < n) {
        if (eligible(target, current)) {
            if (j - i < cur) {
                result = s.substr(i, j - i);
                cur = j - i;
            }
            current[tolower(s[i++]) - 'a']--;
        } else {
            current[tolower(s[j++]) - 'a']++;
        }
    }
    while (eligible(target, current)) {
        if (j - i < cur) {
            result = s.substr(i, j - i);
            cur = j - i;
        }
        current[tolower(s[i++]) - 'a']--;
    }
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s, t;
        cin >> s;
        cin >> t;
        cout << minWindow(s, t) << endl;
    }
    return 0;
}

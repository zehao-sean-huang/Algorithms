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

void search(string& s, int idx, vs& current, vs& result) {
    // base case
    if (idx == s.size()) {
        if (current.size() == 4) {
            // add current to result
            string ip = "";
            for (int i = 0; i < 3; ++i) {
                ip += (current[i] + ".");
            }
            ip += current[3];
            result.push_back(ip);
        }
        return;
    }
    if (current.size() >= 4) return;
    // recursion
    for (int i = 1; i <= min(s.size() - idx, 3ul); ++i) {
        int part = stoi(s.substr(idx, i));
        if ((i == 1) || (i > 1 && pow(10, i - 1) <= part && part < min(int(pow(10, i)), 256))) {
            current.push_back(s.substr(idx, i));
            search(s, idx + i, current, result);
            current.pop_back();
        }
    }
}

vs restoreIpAddresses(string s) {
    vs current;
    vs result;
    int pos = 0;
    search(s, 0, current, result);
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        printVector(restoreIpAddresses(s));
    }
    return 0;
}

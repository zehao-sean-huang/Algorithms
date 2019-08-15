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

vs fullJustify(vs& words, int maxWidth) {
    int n = len(words), i = 0;
    vs r;
    while (i < n) {
        int j = i + 1;
        int currLen = len(words[i]);
        while (j < n) {
            if (currLen + 1 + len(words[j]) <= maxWidth) {
                currLen += (1 + len(words[j]));
                j++;
            } else break;
        }
        int cnt = j - i;
        int chcnt = currLen - (j - i - 1);
        string line = "";
        if (j == n) {
            line = words[i++];
            int spsl = maxWidth - chcnt;
            while (i < j) {
                line += (' ' + words[i++]);
                spsl--;
            }
            if (spsl) line += string(spsl, ' ');
        } else if (cnt > 1) {
            cnt -= 1;
            int left = cnt;
            int spss[cnt];
            memset(spss, 0, cnt);
            int spsl = maxWidth - chcnt;
            for (int k = 1; k <= cnt; k++) {
                spss[cnt - k] = spsl / left;
                spsl -= spss[cnt - k];
                left--;
            }
            line = words[i++];
            int k = 0;
            while (i < j) {
                line += string(spss[k++], ' ') + words[i++];
            }
        } else {
            line = words[i] + string(maxWidth - chcnt, ' ');
        }
        r.push_back(line);
        i = j;
    }
    return r;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vs ws = readStringVector();
        int mw = readNumber();
        for (string s : fullJustify(ws, mw)) {
            cout << s << endl;
        }
    }
    return 0;
}

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

vector<int> grayCode(int n) {
    if (n == 0) {
        return {0};
    } else if (n == 1) {
        return {0, 1};
    }
    vi ans = {0,1,3,2};
    if (n == 2) {
        return ans;
    }
    int t = 2;
    for (int i = 2; i < n; ++i) {
        t *= 2;
        int s = ans.size();
        for (int j = s - 1; j >= 0; j--) {
            ans.push_back(ans[j] + t);
        }
    }
    return ans;
}
 
int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        printVector(grayCode(readNumber()));
    }
    return 0;
}
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

vector<int> pathInZigZagTree(int label) {
    if (label == 1) return {1};
    int level = int(log2(label)) + 1;
    vector<int> result{label};
    while (level > 1) {
        level -= 1;
        label = (1 << level) + (1 << (level - 1)) - 1 - label / 2;
        result.push_back(label);
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        printVector(pathInZigZagTree(readNumber()));
    }
    return 0;
}
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

int lastStoneWeight(vector<int>& stones) {
    if (stones.size() == 1) return stones[0];
    sort(stones.begin(), stones.end(), greater<int>());
    int n = stones.size();
    for (int i = 0; i < n - 1; ++i) {
        if (stones[0] == stones[1]) {
            stones.erase(stones.begin());
            stones.erase(stones.begin());
            i++;
        } else {
            // stones[0] > stones[1];
            stones[1] = stones[0] - stones[1];
            stones.erase(stones.begin());
            int j = 0; 
            while (j < stones.size() - 1) {
                if (stones[j] < stones[j + 1]) {
                    swap(stones[j], stones[j + 1]);
                    j++;
                }
                else break;
            }
        }
    }
    return stones.empty() ? 0 : stones[0];
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vi weights = readVector();
        cout << lastStoneWeight(weights) << endl;
    }
    return 0;
}

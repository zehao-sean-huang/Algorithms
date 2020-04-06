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

void moveZeroes(vector<int>& nums) {
    if (nums.empty()) return;
    int n = nums.size();
    int zeros = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] == 0) {
            zeros++;
        } else if (zeros > 0) {
            swap(nums[i], nums[i - zeros]);
        }
    }
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vi nums = readVector();
        moveZeroes(nums);
        printVector(nums);
    }
    return 0;
}

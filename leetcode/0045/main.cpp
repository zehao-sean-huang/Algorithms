#include "../leetcode.h"

using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size(), h = 0, s = 0, e = 0;
    while (e < n - 1) {
        h += 1;
        int me = e + 1;
        for (int i = s; i <= e; ++i) {
            if (i + nums[i] >= n - 1) return h;
            me = max(me, s + nums[i]);
        }
        s = e + 1;
        e = me;
    }
    return h;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<int> nums = readVector();
        cout << jump(nums) << endl;
    }
    return 0;
}

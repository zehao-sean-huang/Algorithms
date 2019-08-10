#include "../leetcode.h"

using namespace std;

bool canJump(vector<int>& nums) {
    int s = 0, e = 0, n = nums.size();
    while (s <= e) {
        int me = e;
        for (int i = s; i <= e; ++i) {
            me = max(me, i + nums[i]);
        }
        if (me >= n - 1) return true;
        s = e + 1;
        e = me;
    }
    return false;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<int> nums = readVector();
        cout << (canJump(nums) ? "true" : "false") << endl;
    }
    return 0;
}

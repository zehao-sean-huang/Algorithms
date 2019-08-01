#include "../leetcode.h"

using namespace std;

void search(vector<int>& nums, int t, int s, int e, int &r) {
    if (s > e) {
        return;
    } else if (s == e) {
        if (r == -1) {
            r = s;
        }
        return;
    }
    int m = (s + e) >> 1;
    if (t <= nums[m]) {
        search(nums, t, s, m, r);
    } else {
        search(nums, t, m+1, e, r);
    }
}

int searchInsert(vector<int>& nums, int target) {
    int ans = -1;
    search(nums, target, 0, nums.size(), ans);
    return ans;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<int> nums = readVector();
        int target = readNumber();
        cout << searchInsert(nums, target) << endl;
    }
    return 0;
}

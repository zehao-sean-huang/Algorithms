#include "../leetcode.h"

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int ans = 1, i = 0;
    while (i < nums.size()) {
        if (nums[i] == ans) {
            ans++;
            i = 0;
        }
        else {
            i++;
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
        vector<int> nums = readVector();
        cout << firstMissingPositive(nums) << endl;
    }
    return 0;
}

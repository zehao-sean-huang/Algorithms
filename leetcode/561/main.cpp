#include "../leetcode.h"

using namespace std;

int arrayPairSum(vector<int>& nums) {
    int result = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < len(nums); i += 2) {
        result += nums[i];
    }
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int n = readNumber();
        vector<int> nums = readVector(n);
        cout << arrayPairSum(nums) << endl;
    }
    return 0;
}
#include "../leetcode.h"

using namespace std;

vector<vector<int>> permute(vector<int>& nums) {
    if (nums.empty()) {
        return {{}};
    }
    vector<vector<int>> result;
    for (int i = 0; i < nums.size(); ++i) {
        int n = nums[i];
        nums.erase(nums.begin() + i);
        for (vector<int> p : permute(nums)) {
            p.insert(p.begin(), n);
            result.push_back(p);
        }
        nums.insert(nums.begin() + i, n);
    }
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<int> nums = readVector();
        printGrid(permute(nums));
    }
    return 0;
}

#include "../leetcode.h"

using namespace std;

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> r;
    if (nums.empty()) return {{}};
    sort(nums.begin(), nums.end());
    int n = nums.size(), i = 0;
    while (i < n) {
        int j = i, nn = nums[i];
        while (nums[j] == nn) {
            j += 1;
            if (j == nums.size()) break;
        }
        nums.erase(nums.begin() + i);
        for (vector<int> p : permuteUnique(nums)) {
            p.insert(p.begin(), nn);
            r.push_back(p);
        }
        nums.insert(nums.begin() + i, nn);
        i = j;
    }
    return r;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<int> nums = readVector();
        printGrid(permuteUnique(nums));
    }
    return 0;
}

#include "../leetcode.h"

using namespace std;

int removeDuplicates(vector<int>& nums) {
    auto i = unique(nums.begin(), nums.end());
    nums.resize(distance(nums.begin(), i));
    return nums.size();
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<int> nums = readVector();
        cout << removeDuplicates(nums) << endl;
        printVector(nums);
    }
    return 0;
}

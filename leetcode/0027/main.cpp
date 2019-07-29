#include "../leetcode.h"

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int index = 0;
    while (index < nums.size()) {
        if (nums[index] == val) {
            nums.erase(nums.begin() + index);
        } else {
            index++;
        }
    }
    return nums.size();
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<int> nums = readVector();
        cout << removeElement(nums, readNumber()) << endl;
    }
    return 0;
}

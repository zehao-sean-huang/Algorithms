#include "../leetcode.h"

using namespace std;

int trap(vector<int>& height) {
    int n = height.size(), ans = 0;
    int* l = (int*) malloc(sizeof(int) * n);
    int* r = (int*) malloc(sizeof(int) * n);
    l[0] = height[0];
    r[n-1] = height[n-1];
    for (int i = 1; i < n; ++i) {
        l[i] = max(height[i], l[i-1]);
    }
    for (int i = n-2; i >= 0; --i) {
        r[i] = max(height[i], r[i+1]);
    }
    for (int i = 0; i < n; ++i) {
        ans += min(l[i], r[i]) - height[i];
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
        cout << trap(nums) << endl;
    }
    return 0;
}

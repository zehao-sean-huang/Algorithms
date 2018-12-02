#include "../leetcode.h"

using namespace std;

int maxArea(vector<int> height) {
    int n = height.size();
    int ans = 0;
    for (int i = 1; i <= n - 1; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            ans = max(ans, (j - i) * min(height[i - 1], height[j - 1]));
        }
    }
    return ans;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    cout << maxArea(readVector(9)) << endl;
    return 0;
}
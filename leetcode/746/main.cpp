#include "../leetcode.h"

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int ans1 = 0, ans2 = 0;
    for (int i = cost.size() - 1; i >= 0; i--) {
        int ans0 = cost[i] + min(ans1, ans2);
        ans2 = ans1;
        ans1 = ans0;
    }
    return min(ans1, ans2);
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    vector<int> cost = readVector(10);
    cout << minCostClimbingStairs(cost) << endl;
    return 0;
}

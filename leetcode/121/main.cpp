#include "../leetcode.h"

using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size(), maxp = 0;
    int search[n + 10];
    memset(search, 0, sizeof(search));
    for (int i = 1; i <= n; ++i) {
        search[i] = 0;
        for (int j = i - 1; j >= 1; --j) {
            if (prices[j - 1] < prices[i - 1]) {
                search[i] = prices[i - 1] - prices[j - 1] + search[j];
                maxp = max(maxp, search[i]);
                break;
            }
        }
    }
    return maxp;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    vector<int> prices = readVector(6);
    cout << maxProfit(prices) << endl;
    return 0;
}
#include "../leetcode.h"

using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    if (n == 1) return 0;
    int current = 0;
    for (int i = 1; i < n; ++i) {
        if (prices[i] - prices[i - 1] > 0) {
            current += prices[i] - prices[i - 1];
        }
    }
    return current;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<int> prices = readVector();
        cout << maxProfit(prices) << endl;
    }
    return 0;
}

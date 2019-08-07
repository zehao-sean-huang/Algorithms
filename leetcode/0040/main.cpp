#include "../leetcode.h"

using namespace std;

void search(vector<vector<int>> &r, vector<int>& ns, int i, int t, int p, vector<int>& c) {
    if (t == 0) {
        r.push_back(c);
    } else if (t < 0 || i >= ns.size()) {
        return;
    } else if (ns[i] > t) {
        return;
    } else if (p == ns[i]) {
        search(r, ns, i+1, t, p, c);
    } else {
        // use the number
        c.push_back(ns[i]);
        search(r, ns, i + 1, t - ns[i], p, c);
        c.erase(c.end() - 1, c.end());
        // ignore the number
        search(r, ns, i + 1, t, ns[i], c);
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> current;
    search(result, candidates, 0, target, INT_MIN, current);
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<int> nums = readVector();
        int target = readNumber();
        printf("===== Test Case %d =====\n", i);
        vector<vector<int>> r = combinationSum2(nums, target);
        for (vector<int> v : r) printVector(v);
    }
    return 0;
}

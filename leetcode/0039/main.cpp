#include "../leetcode.h"

using namespace std;

void search(vector<vector<int>> &r, vector<int>& ns, int i, int t, vector<int>& c) {
    if (t == 0) {
        r.push_back(c);
    } else if (t < 0 || i >= ns.size()) {
        return;
    } else if (ns[i] > t) {
        return;
    } else {
        int u = 0;
        while (u * ns[i] <= t) {
            search(r, ns, i+1, t-u*ns[i], c);
            c.push_back(ns[i]);
            u += 1;
        }
        c.erase(c.end() - u, c.end());
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> c;
    search(result, candidates, 0, target, c);
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
        vector<vector<int>> r = combinationSum(nums, target);
        for (vector<int> v : r) printVector(v);
    }
    return 0;
}

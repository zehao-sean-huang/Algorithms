#include <bits/stdc++.h>

using namespace std;

void compute(vector<int> &rs, int i, int &size, int r) {
    if (find(rs.begin(), rs.end(), r) != rs.end()) {
        size = rs.size() - (find(rs.begin(), rs.end(), r) - rs.begin());
        return;
    } else {
        if (r == 0) {
            size = 0;
            return;
        }
        rs.push_back(r);
        compute(rs, i, size, 10 * (r % i));
    }
}

int main() {
    int n = 1000, m = INT_MIN, ans = 0;
    for (int i = 2; i < n; ++i) {
        vector<int> rs;
        int size = 0;
        compute(rs, i, size, 10);
        if (size > m) {
            m = size;
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}

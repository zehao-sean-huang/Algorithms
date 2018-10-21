#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

int n;
int l[100010];

ll min(ll a, ll b) {
    return a > b ? b : a;
}

ll help(int position) {
    if (position == n - 1) {
        return l[position] + 1;
    } else {
        ll r = 0;
        int fmax = l[position];
        for (int i = position ; i < n; ++i) {
            fmax = min(l[i] / (i - position + 1), fmax);
        }
        for (int i = 0; i < fmax; ++i) {
            r += help(position + 1);
            for (int j = position + 1; j < n; ++j) {
                l[j] -= (j - position + 1);
            }
        }
        r += help(position + 1);
        for (int j = position + 1; j < n; ++j) {
            l[j] += (j - position + 1) * fmax;
        }
        return r;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &l[i]);
    }
    cout << help(0) << endl;
    return 0;
}
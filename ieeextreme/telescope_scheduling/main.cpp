#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll result[1010][1010];
ll n;

struct Star{
    ll start;
    ll end;
    ll value;
};

Star stars[10010];

ll min(ll a, ll b) {
    return a > b ? b : a;
}

ll max(ll a, ll b) {
    return a > b ? a : b;
}

int main() {
    cin >> n;
    ll s = 1010, e = 0;
    memset(result, 0, sizeof(result));
    for (ll i = 1; i <= n; ++i) {
        ll start, end, value;
        cin >> start >> end >> value;
        s = min(s, start); e = max(e, end);
        stars[i].start = start;
        stars[i].end = end;
        stars[i].value = value;
    }
    for (ll i = 1; i <= n; ++i) {
        for (ll j = s; j <= e; ++j) {
            for (ll k = j; k <= e; ++k) {
                if (j <= stars[i].start && k >= stars[i].end) {
                    result[j][k] = max(result[j][k], stars[i].value + result[j][stars[i].start - 1] + result[stars[i].end + 1][k]);
                }
            }
        }
    }
    for (ll i = 1; i <= e; ++i) {
        for (ll j = i; j <= e; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << result[s][e] << endl;
}

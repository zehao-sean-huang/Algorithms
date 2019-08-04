#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll m, n, a;
    cin >> n >> m >> a;
    n = n % a ? n / a + 1 : n / a;
    m = m % a ? m / a + 1 : m / a;
    cout << m * n << endl;
    return 0;
}

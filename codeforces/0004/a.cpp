#include <bits/stdc++.h>

#define rep(name, start, end, step) for (int name = start; name <= end; name += step)

using namespace std;

#define Pn(x) printf("%d\n", x)
#define Ps(x) printf("%d ", x)

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB

inline void R(int &x) {
    x = 0; int f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {
        if (ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
}

void Redirect() {

}

#define CLX(x) memset(x,0,sizeof x)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main() {
    int w = 0;
    R(w);
    cout << (w > 2 && w % 2 == 0 ? "YES" : "NO") << endl;
    return 0;
}

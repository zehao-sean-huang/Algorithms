#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long ll;
#define sz(a) int((a).size())
#define pb push_back
#define tr(c,it)\
for(typeof(c.begin())it=c.begin();it!=c.end();it++)

#define REP(i,n)\
for(int i=0;i<n;i++)

#define FOR(i,a,b)\
for(int i=a;i<=b;i++)

#define sz(data) sizeof(data)/sizeof(data[0])

#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mk(i,j) make_pair(i,j)
#define pb(c,it) c.push_back(it)

#define INF 10000000
#define PI 3.141592
#define epsilon 1.0e-4

#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)

inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

int main() {
    int m = 0, n = 0;
    R(m), R(n);
    Pn(m * n / 2);
}

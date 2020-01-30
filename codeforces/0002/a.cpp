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
    int n = 0;
    R(n);
    unordered_map<string, vector<pair<int, int>>> m;
    int ms = 0;
    for (int i = 0; i < n; ++i) {
        string name = "";
        int score = 0;
        cin >> name;
        R(score);
        if (m.find(name) == m.end()) {
            m[name] = {make_pair(i, score)};
        } else {
            m[name].push_back(make_pair(i, m[name][m[name].size() - 1].second + score));
        }
    }
    for (auto entry : m) {
        ms = max(ms, entry.second[entry.second.size() - 1].second);
    }
    string winner = "";
    int earliest = 1001;
    for (auto entry : m) {
        if (entry.second[entry.second.size() - 1].second == ms) {
            vector<pair<int,int>>& record = entry.second;
            for (int i = 0; i < record.size(); ++i) {
                if (record[i].second >= ms && record[i].first < earliest) {
                    winner = entry.first;
                    earliest = record[i].first;
                }
            }
        }
    }
    cout << winner << endl;
    return 0;
}

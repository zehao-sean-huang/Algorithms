#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int N;
struct r{
    int a;
    int b;
    int g;
    int k;
};
int x, y;
r rs[10010];
bool in(r tr) {
    if (x >= tr.a && x <= tr.a + tr.g && y >= tr.b && y <= tr.b + tr.k) return true;
    return false;
}
int main() {
    int a, b, g, k;
    r tr;
    scanf("%d",&N);
    for (int i = 1; i <= N; ++i){
        scanf("%d%d%d%d",&a, &b, &g, &k);
        tr.a = a;
        tr.b = b;
        tr.g = g;
        tr.k = k;
        rs[i] = tr;
    }
    scanf("%d%d", &x, &y);
    int re = -1;
    for (int i = 1; i <= N; ++i) {
        if (in(rs[i])) {
            re = i;
        }
    }
    cout << re << endl;
}

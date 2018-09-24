#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct person {
    int w;
    int i;
    int d;
};

int n, k;
int e[11];
vector<person> p;

bool compare(person p1, person p2) {
    if (p1.w != p2.w) {
        return p1.w > p2.w;
    }
    return p1.i < p2.i;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= 10; ++i) {
        cin >> e[i];
    }
    for (int i = 0; i < n; ++i) {
        int tempw;
        cin >> tempw;
        person t = {tempw, i + 1, 0};
        p.push_back(t);
    }
    sort(p.begin(), p.end(), compare);
    for (int i = 0; i < n; ++i) {
        p[i].d = i % 10;
        p[i].w += e[p[i].d];
    }
    sort(p.begin(), p.end(), compare);
    cout << p[0].i;
    for (int i = 1; i < k; ++i) {
        cout << " " << p[i].i;
    }
    return 0;
}

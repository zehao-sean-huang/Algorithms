#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

struct person {
    string name;
    bool outside;
};

int m = 0, n = 0;
person people[100010];

int main () {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> people[i].outside >> people[i].name;
    }
    int a, s;
    int c = 0;
    for (int i = 0; i < m; ++i) {
        cin >> a >> s;
        c = (c - (a == people[c].outside ? 1 : -1) * s) % n;
        c = c < 0 ? n + c : c;
    }
    cout << people[c].name << endl;
    return 0;
}
#include <iostream>
#include    <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n;

struct student {
    string name;
    int index;
    int award;
};

student s[110];

int compute(int f, int c, int p, string l, string w) {
    int r = 0;
    if (f > 80 && p > 0) {
        r += 8000;
    }
    if (f > 85 && c > 80) {
        r += 4000;
    }
    if (f > 90) {
        r += 2000;
    }
    if (w == "Y" && f > 85) {
        r += 1000;
    }
    if (c > 80 && l == "Y") {
        r += 850;
    }
    return r;
}

bool compare(student a, student b) {
    if (a.award != b.award) {
        return a.award > b.award;
    } else {
        return a.index < b.index;
    }
}

int main() {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        string name;
        int f, c, p;
        string l, w;
        cin >> name >> f >> c
            >> l >> w >> p;
        s[i].name = name;
        s[i].index = i;
        s[i].award = compute(f, c, p, l, w);
        sum += s[i].award;
    }
    sort(s, s + n, compare);
    cout << s[0].name << endl
        << s[0].award << endl
        << sum << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct p {
    string v;
    int i;
};

int n;
vector<p> votes;

bool compare(p v1, p v2) {
    if (v1.v.size() > v2.v.size()) {
        return true;
    } else if (v1.v.size() < v2.v.size()) {
        return false;
    } else {
        return v1.v > v2.v;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;
        p tp = {t, i + 1};
        votes.push_back(tp);
    }
    sort(votes.begin(), votes.end(), compare);
    cout << votes[0].i << endl;
    cout << votes[0].v << endl;
}
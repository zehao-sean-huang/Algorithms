#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

pair<int, int> e[6000];
pair<int, int> t[6000];
int ei = 0, ti = 0; 
pair<int, int> ec, tc;

bool closed(pair<int, int> score, int sys) {
    if (score.first >= sys || score.second >= sys) {
        if (abs(score.first - score.second) < 2) {
            return false;
        } else {
            return true;
        }
    }
    return false;
}

void clear(pair<int, int> &score) {
    score.first = 0;
    score.second = 0;
}

void process(char c) {
    if (c == 'W') {
        ++ec.first;
        ++tc.first;
    } else if (c == 'L') {
        ++ec.second;
        ++tc.second;
    }
    if (closed(ec, 11)) {
        e[ei] = ec;
        clear(ec);
        ++ei;
    }
    if (closed(tc, 21)) {
        t[ti] = tc;
        clear(tc);
        ++ti;
    }
}

int main() {
    char current;
    while (cin.get(current)) {
        if (current == 'E') {
            if (ec.first != 0 || ec.second != 0) {
                e[ei] = ec;
            }
            if (tc.first != 0 || tc.second != 0) {
                t[ti] = tc;
            }
            break;
        }
        process(current);
    }
    for (int i = 0; i <= ei; ++i) {
        cout << e[i].first << ":" << e[i].second << endl;
    }
    cout << endl;
    for (int i = 0; i <= ti; ++i) {
        cout << t[i].first << ":" << t[i].second << endl;
    }
    return 0;
}
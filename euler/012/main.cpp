#include <bits/stdc++.h>

using namespace std;

map<int, pair<int, int> > computed;

pair<int, int> compute(int current) {
    if (computed.find(current) == computed.end()) {
        if (current % 2 == 0) {
            pair<int, int> half = compute(current / 2);
            computed[current] = make_pair(half.first + 1, half.second / (half.first + 1) * (half.first + 2));
        } else {
            int ans = 0;
            for (int i = 1; i <= int(sqrt(current)) + 1; ++i) {
                if (current % i == 0) {
                    ans += 2;
                }
                if (i * i == current) {
                    ans -= 1;
                }
                computed[current] = make_pair(0, ans);
            } 
        }
    }
    return computed[current];
}

int main() {
    int current = 3, number = 3;
    computed[1] = make_pair(0, 1);
    computed[2] = make_pair(1, 2);
    computed[3] = make_pair(0, 2);
    computed[4] = make_pair(2, 3);
    computed[5] = make_pair(0, 2);
    while (compute(number).second <= 500) {
        int twoCount = compute(current).first + compute(current + 1).first;
        int divCount = compute(current).second * compute(current + 1).second;
        divCount = divCount / (twoCount + 1) * twoCount;
        number = current * (current + 1) / 2;
        computed[number] = make_pair(twoCount - 1, divCount);
        current += 1;
    }
    cout << number << endl;
    return 0;
}

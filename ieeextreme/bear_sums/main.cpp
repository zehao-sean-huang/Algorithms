#include <bits/stdc++.h>

using namespace std;

int T;

int main() {
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        int S, E, t;
        scanf("%d %d", &S, &E);
        set<int> ns;
        bool result = false;
        for (int j = 0; j < E; ++j) {
            scanf("%d", &t);
            if (ns.find(S - t) != ns.end() && !result) {
                if (S - t >= t) {
                    cout << t << " " << S - t << endl;
                } else {
                    cout << S - t << " " << t << endl;
                }
                result = true;
            } else if (ns.find(t) == ns.end()) {
                ns.insert(t);
            }
        }
        if (!result) {
            cout << "!OK" << endl;
        }
    }
    return 0;
}
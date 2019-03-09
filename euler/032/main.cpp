#include "../euler.h"
#define str(x) string(to_string(x))

using namespace std;

set<int> r;

bool judge(int i, int j) {
    string s = str(i) + str(j) + str(i * j);
    sort(s.begin(), s.end());
    return s == "123456789";
}

int main() {
    for (int i = 1; i < 1000; ++i) {
        for (int j = i + 1; j < 10000; ++j) {
            if (judge(i, j)) {
                cout << i << " " << j << " " << i * j << endl;
                r.insert(i * j);
            }
        }
    }
    int sum = 0;
    for (int p : r) {
        sum += p;
    }
    cout << sum << endl;
    return 0;
}
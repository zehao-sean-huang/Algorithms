#include "../euler.h"

using namespace std;

set<string> r;

int main() {
    for (int a = 2; a <= 100; ++a) {
        for (int b = 2; b <= 100; ++b) {
            r.insert(power(a, b));
        }
    }
    cout << r.size() << endl;
    return 0;
}
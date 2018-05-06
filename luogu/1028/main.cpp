#include <iostream>
#include <string>
#include <map>

using namespace std;

map<int, int> r;

int p(int m) {
    int result = 1;
    for (int i = 1; i <= m / 2; ++i) {
        if (r.find(i) == r.end()) {
            r[i] = p(i);
        }
        result += r[i];
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    cout << p(n) << endl;
    return 0;
}

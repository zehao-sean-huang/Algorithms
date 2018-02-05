#include <iostream>
#include <cmath>
using namespace std;
bool check(int n) {
    if (n == 2) return true;
    int l = int(sqrt(n));
    for (int i = 2; i <= l; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    if (check(n)) cout << "\\t";
    else cout << "\\n";
    return 0;
}
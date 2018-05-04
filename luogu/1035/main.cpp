#include <iostream>
using namespace std;
int main() {
    int k, n;
    cin >> k;
    for (double sn = 0.0; sn <= k; ++n, sn += 1.0 / n);
    cout << n << endl;
    return 0;
}

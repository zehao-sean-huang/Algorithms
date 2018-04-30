#include <iostream>
using namespace std;
int main() {
    double k;
    int n = 1;
    cin >> k;
    double p = 2.0;
    for (double d = 2.0; d <= k; ++n, d += (p = p * 0.98));
    cout << n << endl;
    return 0;
}

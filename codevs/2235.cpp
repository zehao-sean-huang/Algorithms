#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
    int p;
    double d;
    cin >> p >> d;
    cout << int(double(p) * d / 100 + 0.5) * 10 << endl;
    return 0;
}
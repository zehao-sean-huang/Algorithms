#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double a;
    cin >> a;
    cout.width();
    cout << fixed << setprecision(2) << a << endl;
}
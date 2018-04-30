#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int a;
    cin >> a;
    cout.setf(ios::fixed);
    if (a <= 150) {
        cout << setprecision(1) <<  0.4463 * a << endl;
    } else if (a <= 400) {
        cout << setprecision(1) <<  0.4463 * 150 + 0.4663 * (a - 150) << endl;
    } else {
        cout << setprecision(1) <<  0.4463 * 150 + 0.4663 * 250 + (a - 400) * 0.5663 << endl;
    }
    return 0;
}

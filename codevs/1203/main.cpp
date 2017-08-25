#include <iostream>
#include <string>
using namespace std;
int main() {
    double a,b;
    cin >> a >> b;
    a *= 100000000;
    b *= 100000000;
    if (int(a) == int(b)) cout << "yes";
    else cout << "no";
    return 0;
}
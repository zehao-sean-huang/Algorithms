#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int minutes = (c - a) * 60 + (d - b);
    int hours = minutes / 60;
    cout << hours << " " << minutes - 60 * hours << endl;
    return 0;
}

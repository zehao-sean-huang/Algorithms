#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    for (int a = 1; a <= 499; ++a) {
        for (int b = a; b < 1000 - a; ++b) {
            int c = 1000 - a - b;
            if (a*a + b*b == c*c) {
                cout << a << endl;
                cout << b << endl;
                cout << c << endl;
                cout << a*b*c << endl;
                break;
            }
        }
    }
    return 0;
}

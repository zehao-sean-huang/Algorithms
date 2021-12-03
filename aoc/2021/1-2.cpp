#include <iostream>

using namespace std;

int main() {
    #ifndef ONLINEJUDGE
    freopen("day01.in", "r", stdin);
    #endif

    int a = 0;
    int b = 0;
    int c = 0;

    cin >> a;
    cin >> b;
    cin >> c;

    int d;
    int curr = a + b + c;
    int next;

    int result = 0;

    while (cin >> d) {
        next = curr - a + d;
        if (next > curr) {
            result ++; 
        }
        a = b;
        b = c;
        c = d;
    }

    cout << result << endl;
}

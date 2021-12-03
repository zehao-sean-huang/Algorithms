#include <iostream>

using namespace std;

int main() {
    #ifndef ONLINEJUDGE
    freopen("day01.in", "r", stdin);
    #endif

    int c, n;
    int result = 0;
    cin >> c;
    while (cin >> n) {
        if (n > c) result++;
        c = n;
    } 
    cout << result << endl;
    return 0;
}

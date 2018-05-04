#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int money = 10 * a + b;
    cout << money / 19 << endl;
    return 0;
}

#include <iostream>
using namespace std;
int main() {
    int index = 0;
    int max = 0;
    for (int i = 1; i <= 7; ++i) {
        int a, b;
        cin >> a >> b;
        int hour = a + b;
        if (hour > 8) {
            if (hour > max) {
                index = i;
                max = hour;
            }
        }
    }
    cout << index << endl;
    return 0;
}

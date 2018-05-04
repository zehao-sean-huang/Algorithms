#include <iostream>

using namespace std;

int a[110];

int main() {
    int temp = 1;
    int i = 1;
    while (temp != 0) {
        cin >> temp;
        if (temp) {
            a[i++] = temp;
        }
    }
    int len = i - 1;
    for (i = len; i > 1; --i) {
        cout << a[i] << " ";
    }
    cout << a[1] << endl;
    return 0;
}

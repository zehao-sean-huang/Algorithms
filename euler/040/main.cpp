#include "../euler.h"

using namespace std;

int helper(int n) {
    int r, s = 0, k = 0;
    while (s < n) {
        r = s;
        s += 9 * pow(10, k++) * k;
    }
    int h = n - r - 1;
    int t = pow(10, k - 1) + h / k;
    int p = h % k;
    return string(to_string(t))[p] - '0';
}

int main() {
    int result = 1;
    for (int i = 0; i < 7; ++i) {
        int temp = helper(pow(10, i));
        cout << temp << " ";
        result *= temp;
    }
    cout << endl;
    cout << result << endl;
    return 0;
}

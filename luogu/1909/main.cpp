#include <iostream>
#include <limits>
using namespace std;
int main() {
    int n;
    cin >> n;
    int min = std::numeric_limits<int>::max();
    int a, b;
    for (int i = 1; i <= 3; ++i) {
        cin >> a >> b;
        if ((n / a + (n % a ? 1 : 0)) * b < min) {
            min = ((n / a + (n % a ? 1 : 0)) * b);
        }
    }
    cout << min << endl;
}

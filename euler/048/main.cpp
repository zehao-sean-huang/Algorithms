#include "../euler.h"

using namespace std;

int main() {
    string sum = "0";
    for (int i = 1; i <= 1000; ++i) {
        sum = add(sum, power(i, i));
    }
    cout << sum << endl;
    return 0;
}

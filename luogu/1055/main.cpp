#include <iostream>
#include <string>

using namespace std;

int main() {
    string isbn;
    cin >> isbn;
    int sum = 0;
    for (int i = 1, j = 1; i <= 11; ++i, ++j) {
        if (i == 2 || i == 6) {
            ++i;
        }
        sum += (isbn[i - 1] - 48) * j;
    }
    sum %= 11;
    if ((sum == 10 ? 'X' : char(sum + 48)) == isbn[12]) {
        cout << "Right" << endl;
    } else {
        cout << isbn.substr(0, isbn.size() - 1) 
            << (sum == 10 ? 'X' : char(sum + 48)) << endl;
    }
    return 0;
}

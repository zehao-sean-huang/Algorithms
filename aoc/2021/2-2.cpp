#include <iostream>
#include <string>

using namespace std;

int main() {
    #ifndef ONLINEJUDGE
    freopen("day02.in", "r", stdin);
    #endif

    string operation;
    int value;

    int horizontal = 0;
    int aim = 0;
    int depth = 0;

    while (cin >> operation >> value) {
        if (operation == "forward") {
            horizontal += value;
            depth += (aim * value);
        } else if (operation == "up") {
            aim -= value;
        } else if (operation == "down") {
            aim += value;
        }
    }

    cout << horizontal << " " << depth << endl;
    cout << horizontal * depth << endl;
    
    return 0;
}

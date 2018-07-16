#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int p1, p2, p3;
string input;

bool expandable(char b, char c, char a) {
    if (c != '-') return false;
    if (b >= a) return false;
    if (isupper(b) && isupper(a)) return true;
    if (islower(b) && islower(a)) return true;
    if (isdigit(b) && isdigit(a)) return true;
    return false;
}

void expand(char before, char after) {
    string output;
    for (char i = before + 1; i != after; ++i) {
        for (int j = 1; j <= p2; ++j) {
            switch (p1) {
                case 1: {
                    if (isalpha(before)) {
                        output += tolower(i);          
                    } else {
                        output += i;
                    }
                    break;
                } case 2: {
                    if (isalpha(before)) {
                        output += toupper(i);
                    } else {
                        output += i;
                    }
                    break;
                } case 3: {
                    output += '*';
                    break;
                }
            }
        }
    }
    if (output.size()) {
        if (p3 == 1) {
            cout << output;
        } else {
            for (int i = output.size() - 1; i >= 0; --i) {
                cout << output[i];
            }
        }
    }
}

int main() {
    cin >> p1 >> p2 >> p3;
    cin >> input;
    char a, b, c;
    cout << input[0];
    for (int i = 1; i < input.size() - 1; ++i) {
        b = input[i - 1], a = input[i + 1], c = input[i];
        if (expandable(b, c, a)) {
            expand(b, a);
        } else {
            cout << c;
        }
    }
    cout << input[input.size() - 1] << endl;
    return 0;
}

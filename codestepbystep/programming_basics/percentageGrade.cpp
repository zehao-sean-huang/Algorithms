#include <iostream>
void percentageGrade() {
    int percent = getInteger("What percentage did you earn? ");
    if (percent >= 90) {
        cout << "You got an A!" << endl;
    }
    else if (percent >= 80) {
        cout << "You got a B!" << endl;
    }
    else if (percent >= 70) {
        cout << "You got a C!" << endl;
    }
    else if (percent >= 60) {
        cout << "You got a D!" << endl;
    }
    else {
        cout << "You got an F!" << endl;
    }
}
#include <iostream>
#include "simpio.h"
using namespace std;
int main() {
    int stanford = getInteger("Stanford: How many points did they score? ","");
    int cal = getInteger("Cal: How many points did they score? ","");
    if (stanford > cal) {
        cout << "Stanford won!" << endl;
    }
    else {
        cout << "Cal won!" << endl;
    }
    return 0;
}
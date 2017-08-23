#include <iostream>
#include "vector.h"
void diceRolls(Vector<int> &result, Vector<int> &choices, int &size) {
    if (result.size() == size) {
        cout << result << endl;
        return;
    }
    for (int i = 0; i < 6; ++i) {
        result += choices[i];
        diceRolls(result, choices, size);
        result.remove(result.size() - 1);
    }
}
void diceRolls(int time) {
    if (time == 0) return;
    Vector<int> result;
    Vector<int> choices = {1,2,3,4,5,6};
    diceRolls(result, choices, time);
}
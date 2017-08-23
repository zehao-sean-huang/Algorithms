#include <iostream>
#include "vector.h"

void printAllDecimal(Vector<int> &result, Vector<int> &choices, int size) {
    if (result.size() == size) {
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i];
        }
        cout << endl;
        return;
    }
    for (int i = 0; i <= 9; ++i) {
        result += choices[i];
        printAllDecimal(result, choices, size);
        result.remove(result.size() - 1);
    }
}
void printAllDecimal(int size) {
    if (size <= 0) return;
    Vector<int> result;
    Vector<int> choices = {0,1,2,3,4,5,6,7,8,9};
    printAllDecimal(result, choices, size);
}
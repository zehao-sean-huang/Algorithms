#include <iostream>
#include "vector.h"
int getSum(Vector<int> &v) {
    int sum = 0;
    for (int i = 0; i < v.size(); ++i){
        sum += v[i];
    }
    return sum;
}
void diceSum(Vector<int> &result, Vector<int> &choices, int &size, int& sum) {
    if (result.size() == size) {
        if (sum == getSum(result)) {
            cout << result << endl;
        }
        return;
    }
    for (int i = 0; i < 6; ++i) {
        result += choices[i];
        diceSum(result, choices, size, sum);
        result.remove(result.size() - 1);
    }
}
void diceSum(int time, int sum) {
    if (time == 0 && sum == 0) return;
    if (time == 0 || sum == 0) return;
    Vector<int> result;
    Vector<int> choices = {1,2,3,4,5,6};
    diceSum(result, choices, time,sum);
}
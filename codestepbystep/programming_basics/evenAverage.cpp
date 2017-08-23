#include <iostream>
#include "simpio.h"
void evenAverage() {
    int cnt=0;
    int num=0;
    int sum=0;
    do {
        num = getInteger("Integer? ","");
        if (num == 0) break;
        else if (num % 2 == 0) {
            ++cnt;
            sum+=num;
        }
    } while (num != 0);
    cout << "Average: " << 1.0 * sum / cnt << endl;
}
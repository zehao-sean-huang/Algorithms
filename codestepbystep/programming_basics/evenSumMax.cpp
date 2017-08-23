#include <iostream>
#include "simpio.h"
void evenSum() {
    int cnt = getInteger("how many integers? ");
    int sum = 0;
    int max = 0;
    for (int i = 1; i <= cnt; ++i) {
        int num = getInteger("next integer? ");
        if (num % 2 == 0) {
            sum += num;
            if (num > max) {
                max = num;
            }
        }
    }
    cout << "even sum = " << sum << endl;
    cout << "even max = " << max << endl;
}
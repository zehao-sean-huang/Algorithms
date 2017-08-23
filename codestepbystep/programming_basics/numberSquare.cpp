#include <iostream>
void numberSquare(int min, int max) {
    int range = max - min + 1;
    for (int i = min; i <= max; ++i) {
        for (int j = 0; j < range; ++j) {
            if (j + i > max) {
                cout << j + i - range;
            }
            else cout << j + i;
        }
        cout << endl;
    }
}
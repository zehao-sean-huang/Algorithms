#include "../euler.h"

using namespace std;

int quota = 10000;

int pentagon(int n) {
    return n * (3 * n - 1) / 2;
}

int main() {
    int numbers[quota + 10];
    set<int> group;
    for (int i = 1; i <= quota; ++i) {
        numbers[i] = pentagon(i);
        group.insert(numbers[i]);
    }
    for (int d = 1; d < quota; ++d) {
        for (int i = 1; i <= quota - d; ++i) {
            int j = i + d;
            if (group.find(numbers[j] - numbers[i]) != group.end()) {
                if (group.find(numbers[i] + numbers[j]) != group.end()) {
                    cout << numbers[i] << " " << numbers[j] << endl;
                    break;
                }
            }
        }
    }
    return 0;
}

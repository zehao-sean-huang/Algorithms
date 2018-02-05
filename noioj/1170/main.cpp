#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    int i=2;
    while (N>i) {
        while (N%i==0) {
            printf("%d*",i);
            N /= i;
        }
        ++i;
    }
    cout << N;
    return 0;
}
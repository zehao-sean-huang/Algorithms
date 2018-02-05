#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;
int N = 0;
int size = 0;
int a[120];
int main() {
    scanf("%d",&N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d",&a[i]);
        if (i / 2 > 0) {
            if (a[i] > a[i / 2]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
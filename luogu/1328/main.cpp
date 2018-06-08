#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, na, nb, ra, rb;
int a[210];
int b[210];

int aw[5][5] = {
        {0, -1, 1, 1, -1},
        {1, 0, -1, 1, -1},
        {-1, 1, 0, -1, 1},
        {-1, -1, 1, 0, 1},
        {1, 1, -1, -1, 0}
    };

int main() {
    cin >> n >> na >> nb;
    for (int i = 0; i < na; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < nb; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        int r = aw[a[i % na]][b[i % nb]];
        if (r == 1) {
            ra++;
        } else if (r == -1) {
            rb++;
        }
    }
    cout << ra << " " << rb << endl;
}
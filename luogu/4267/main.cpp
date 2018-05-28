#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

int N;
int d[110];
int r[110][110][110];

int main() {
    scanf("%d", &N);
    memset(r, 0, sizeof(r));
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &d[i]);
    }
    for (int a = 1; a <= N; ++a) {
        r[a][a][1] = d[a] ? 1 : 0;
    }
    for (int a = 1; a <= N; ++a) {
        for (int b = a + 1; b <= N; ++b) {
            r[a][b][1] = r[a][b - 1][1] + (d[b] == (b - a) ? 0 : 1);
        }
    }
    cout << r[1][N][1] << endl;
    for (int e = 2; e <= N; ++e) {
        for (int a = 1; a <= N - e + 1; ++a) {
            for (int b = a + e - 1; b <= N; ++b) {
                int min = 110;                
                for (int f = 1; f < e; ++f) {
                    int s = e - f;
                    for (int middle = a + f - 1; middle <= b - s; ++middle) {
                        if (r[a][middle][f] + r[middle + 1][b][s] < min) {
                            min = r[a][middle][f] + r[middle + 1][b][s];
                        }
                    }
                }
                r[a][b][e] = min;
            }
        }
        cout << r[1][N][e] << endl;
    }
    return 0;
}

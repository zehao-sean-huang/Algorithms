#include "../leetcode.h"

using namespace std;

void search(bool used[], int index, int &ans, int N) {
    if (index > N) ++ans;
    else {
        for (int i = 1; i <= N; ++i) {
            if (!used[i]) {
                if (i % index == 0 || index % i == 0) {
                    used[i] = true;
                    search(used, index + 1, ans, N);
                    used[i] = false;
                }
            }
        }
    }
}

int countArrangement(int N) {
    bool used[20];
    int ans = 0;
    memset(used, false, sizeof(used));
    search(used, 1, ans, N);
    return ans;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        cout << countArrangement(readNumber()) << endl;
    }
    return 0;
}

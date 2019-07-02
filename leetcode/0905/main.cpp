#include "../leetcode.h"

using namespace std;

vector<int> sortArrayByParity(vector<int>& A) {
    vector<int> result;
    for (int a : A) {
        if (a % 2 == 0) {
            result.insert(result.begin(), a);
        } else {
            result.insert(result.end(), a);
        }
    }
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int n = readNumber();
    vector<int> A = readVector(n);
    printVector(sortArrayByParity(A));
    return 0;
}
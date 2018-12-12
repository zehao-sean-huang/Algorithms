#include "../leetcode.h"

using namespace std;

vector<int> deckRevealedIncreasing(vector<int>& deck) {
    int n = deck.size();
    vector<int> result(n, 0);
    sort(deck.begin(), deck.end());
    result[0] = deck[0];
    int pi = 0;
    for (int i = 1; i < n; ++i) {
        while (result[pi]) {
            pi = pi + 1 >= n ? pi + 1 - n : pi + 1;
        }
        pi = pi + 1 >= n ? pi + 1 - n : pi + 1;
        while (result[pi]) {
            pi = pi + 1 >= n ? pi + 1 - n : pi + 1;
        }
        result[pi] = deck[i];
        pi = pi + 1 >= n ? pi + 1 - n : pi + 1;
    }
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int n = readNumber();
    vector<int> deck = readVector(n);
    printVector(deckRevealedIncreasing(deck));
    return 0;
}

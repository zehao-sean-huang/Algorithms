#include "../leetcode.h"

using namespace std;

void count(map<char, int> &freq, int left, int &r) {
    if (left > 0) {
        for (auto entry : freq) {
            if (entry.second > 0) {
                freq[entry.first] -= 1;
                r += 1;
                count(freq, left - 1, r);
                freq[entry.first] += 1;
            }
        }
    }
}

int numTilePossibilities(string tiles) {
    map<char, int> freq;
    for (char tile : tiles) {
        if (freq.find(tile) != freq.end()) freq[tile] += 1;
        else freq[tile] = 1;
    }
    int result = 0;
    count(freq, tiles.size(), result);
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        cout << numTilePossibilities(s) << endl;
    }
    return 0;
}

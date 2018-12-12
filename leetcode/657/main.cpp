#include "../leetcode.h"

using namespace std;

bool judgeCircle(string moves) {
    int x = 0, y = 0;
    for (char c : moves) {
        switch (c) {
            case 'L': {x--; break;}
            case 'R': {x++; break;}
            case 'U': {y++; break;}
            case 'D': {y--; break;}
        }
    }
    return x == 0 && y == 0;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int n = readNumber();
    for (int i = 0; i < n; ++i) {
        string move = "";
        cin >> move;
        cout << (judgeCircle(move) ? "true" : "false") << endl;
    }   
    return 0;
}
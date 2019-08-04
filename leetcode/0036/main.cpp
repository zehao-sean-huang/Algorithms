#include "../leetcode.h"

using namespace std;

bool helper(vector<char> &v) {
    set<char> s;
    for (char c : v) {
        if (c != '.') {
            if (s.find(c) != s.end()) {
                return false;
            } else {
                s.insert(c);
            }
        }
    }
    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
    // check rows
    for (vector<char>& v : board) {
        if (!helper(v)) {
            return false;
        }
    }
    // check columns
    for (int i = 0; i < 9; ++i) {
        vector<char> v;
        for (int j = 0; j < 9; ++j) {
            v.push_back(board[j][i]);
        }
        if (!helper(v)) {
            return false;
        }
    }
    // check boxes
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            vector<char> v;
            v.push_back(board[i * 3][j * 3]);
            v.push_back(board[i * 3 + 1][j * 3]);
            v.push_back(board[i * 3 + 2][j * 3]);
            v.push_back(board[i * 3][j * 3 + 1]);
            v.push_back(board[i * 3 + 1][j * 3 + 1]);
            v.push_back(board[i * 3 + 2][j * 3 + 1]);
            v.push_back(board[i * 3][j * 3 + 2]);
            v.push_back(board[i * 3 + 1][j * 3 + 2]);
            v.push_back(board[i * 3 + 2][j * 3 + 2]);
            if (!helper(v)) {
                return false;
            }
        }
    }
    return true;
}


int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        ;
    }
    return 0;
}

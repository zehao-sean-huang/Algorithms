#include "../leetcode.h"

using namespace std;

vector<bitset<10>> rs(10, 0);
vector<bitset<10>> cs(10, 0);
vector<bitset<10>> gs(10, 0);

class Solution {
public:

void search(vector<vector<char>>& board, int i, int j, bool& f, vector<bitset<10>>& rs, vector<bitset<10>>& cs, vector<bitset<10>>& gs) {
    if (f) return;
    else if (board[i][j] != '.') {
        if (i == 8 && j == 8) f = true;
        else if (j == 8) search(board, i + 1, 0, f, rs, cs, gs);
        else search(board, i, j + 1, f, rs, cs, gs);
    } else {
        for (int n = 1; n <= 9; ++n) {
            if (!(rs[i][n] | cs[j][n] | gs[i - i % 3 + j / 3][n])) {
                board[i][j] = n + '0';
                rs[i][n] = cs[j][n] = gs[i - i % 3 + j / 3][n] = 1;
                if (i == 8 && j == 8) f = true;
                else if (j == 8) search(board, i + 1, 0, f, rs, cs, gs);
                else search(board, i, j + 1, f, rs, cs, gs);
                if (f) break;
                else {
                    board[i][j] = '.';
                    rs[i][n] = cs[j][n] = gs[i - i % 3 + j / 3][n] = 0;
                }
            }
        }
    }
}

void solveSudoku(vector<vector<char>>& board) {
    // preprocess
    vector<bitset<10>> rs(10, 0);
    vector<bitset<10>> cs(10, 0);
    vector<bitset<10>> gs(10, 0);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                rs[i][board[i][j] - '0'] = 1;
                cs[j][board[i][j] - '0'] = 1;
                gs[i - i % 3 + j / 3][board[i][j] - '0'] = 1;
            }
        }
    }
    bool f = false;
    search(board, 0, 0, f, rs, cs, gs);
    return;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<vector<char>> board = readCharGraph();
        solveSudoku(board);
        printGrid(board);
    }
    return 0;
}

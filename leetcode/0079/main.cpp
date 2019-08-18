#include "../leetcode.h"

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<vector<string>> vvs;
typedef vector<string> vs;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;
typedef pair<int, int> pii;
#define ll long long
#define l long
#define fi(x) x.first
#define se(x) x.second
#define be(x) x.begin()
#define en(x) x.end()
#define str(x) string(to_string(x))
#define ord(x) int(x - '0')
#define chr(x) char(x + '0')
#define len(x) x.size()

void find(vvc& b, int i, int j, string& t, string& c, bool&f, bool* v, int& m, int& n, int idx) {
    if (len(t) == len(c)) f = true;
    if (len(t) <= len(c)) return;
    if (f) return;
    if (i < 0 || i >= len(b) || j < 0 || j >= len(b[0])) return;
    if (b[i][j] != t[idx]) return;
    if (v[i * n + j]) return;
    c.push_back(b[i][j]);
    v[i * n + j] = true;
    find(b, i + 1, j, t, c, f, v, m, n, idx + 1);
    if (f) return;
    find(b, i - 1, j, t, c, f, v, m, n, idx + 1);
    if (f) return;
    find(b, i, j + 1, t, c, f, v, m, n, idx + 1);
    if (f) return;
    find(b, i, j - 1, t, c, f, v, m, n, idx + 1);
    v[i * n + j] = false;
    c.pop_back();
    return;
}
    
bool exist(vvc& board, string word) {
    if (board.empty()) return false;
    if (board[0].empty()) return false;
    if (word.empty()) return false;
    int m = len(board), n = len(board[0]);
    bool f = false;
    bool v[(m + 10) * (n + 10)];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (word[0] == board[i][j]) {
                string c = "";
                memset(v, false, sizeof(v));
                find(board, i, j, word, c, f, v, m, n, 0);
                if (f) return f;
            }
        }
    }
    return false;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vvc b = readCharGraph();
        string w = "";
        while (w.empty()) getline(cin, w);
        cout << (exist(b, w) ? "true" : "false") << endl;
    }
    return 0;
}

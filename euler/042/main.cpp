#include "../euler.h"

using namespace std;

vector<string> words;
int cnt = 0;
set<int> ts;

void parse() {
    string line = "";
    getline(cin, line);
    words = split(line, ",");
}

bool judge(string word) {
    int sum = 0;
    for (char c : word.substr(1, len(word) - 2)) {
        sum += (c - 'A' + 1);
    }
    if (ts.find(sum) != ts.end()) {
        return true;
    }
    return false;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    freopen("main.out", "w", stdout);
    #endif
    parse();
    for (int i = 0; i <= 100; ++i) {
        ts.insert(i * (i + 1) / 2);
    }
    for (string word : words) {
        if (judge(word)) {
            ++cnt;
        }
    }
    cout << cnt << endl;
}
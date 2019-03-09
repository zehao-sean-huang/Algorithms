#include "../leetcode.h"

using namespace std;

pair<int, int> parse(string c) {
    return make_pair(stoi(c.substr(0, c.find("+"))), stoi(c.substr(c.find("+") + 1, c.find("i") - c.find("+") - 1)));
}

string complexNumberMultiply(string a, string b) {
    pair<int, int> ca = parse(a);
    pair<int, int> cb = parse(b);
    return str(ca.first * cb.first - ca.second * cb.second) + "+" + str(ca.first * cb.second + ca.second * cb.first) + "i";
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string a, b;
        cin >> a >> b;
        cout << complexNumberMultiply(a, b) << endl;
    }
    return 0;
}
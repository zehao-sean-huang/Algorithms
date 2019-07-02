#include "../leetcode.h"

using namespace std;

bool judge(string &w1, string &w2, string &order) {
    int s1 = w1.size(), s2 = w2.size();
    for (int i = 0; i < min(s1, s2); ++i) {
        if (order.find(w1[i]) < order.find(w2[i])) {
            return true;
        } else if (order.find(w1[i]) > order.find(w2[i])) {
            return false;
        }
    }
    return s1 <= s2;
}

bool isAlienSorted(vector<string>& words, string order) {
    if (words.size() < 2) {
        return true;
    } else {
        for (int i = 1; i < words.size(); ++i) {
            if (!judge(words[i - 1], words[i], order)) {
                return false;
            }
        }
        return true;
    }
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int n = readNumber();
    for (int i = 0; i < n; ++i) {
        int m = readNumber();
        vector<string> words = readStringVector(m);
        string order;
        cin >> order;
        cout << (isAlienSorted(words, order) ? "true" : "false") << endl;
    }
    return 0;
}

#include <set>
#include <string>
#include <map>
#include <stack>
#include <iostream>
#include <cstdio>

using namespace std;
int N;
map<string, int> chains;

int main() {
    scanf("%d", &N);
    string w;
    int max = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> w;
        string s = w.substr(0, w.size() - 1);
        if (chains.find(w) == chains.end()) chains.insert(make_pair(w, 1));
        while (s.size()) {
            if (chains.find(s) != chains.end()) {
                if (chains[w] < chains[s] + 1) {
                    chains[w] = chains[s] + 1;
                }
            }
            s = s.substr(0, s.size() - 1);
        }
        if (chains[w] > max) max = chains[w];
    }
    cout << max << endl;
    return 0;
}
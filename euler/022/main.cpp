#include <bits/stdc++.h>

using namespace std;

vector<string> names;

void read() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    string line;
    getline(cin, line);
    int current = 0;
    while (line.find(',', current) != string::npos) {
        names.push_back(line.substr(current + 1, line.find(',', current) - current - 2));
        current = line.find(',', current) + 1;
    }
    names.push_back(line.substr(current + 1, line.size() - current - 2));
}

int main() {
    read();
    sort(names.begin(), names.end());
    int n = names.size(), ans = 0;
    for (int i = 1; i <= n; ++i) {
        string& name = names[i - 1];
        int temp = 0;
        for (char c : name) {
            temp += c - 'A' + 1;
        }
        ans += temp * i;
    }
    cout << ans << endl;
    return 0;
}
/**
 * https://csacademy.com/ieeextreme-practice/task/72a7d67e7e18f4f7d033f7f5a5a09bef/statement/
 */

#include <bits/stdc++.h>

using namespace std;

struct Book {
    int time;
    set<string> topics;
};

int b = 0;
int total = 0;
Book books[110];
map<string, int> frequencies;

void helper(int index, map<string, int> &remains, int saves, int &max) {
    // base case:
    if (index == b) {
        if (saves > max) {
            max = saves;
        }
        return;
    }
    // droppable:
    bool droppable = true;
    for (string topic : books[index].topics) {
        if (remains[topic] == 1) {
            droppable = false;
        }
    }
    // drop this book:
    int result_drop = 0;
    if (droppable) {
        for (string topic : books[index].topics) {
            remains[topic]--;
        }
        helper(index + 1, remains, saves + books[index].time, max);
        for (string topic : books[index].topics) {
            remains[topic]++;
        }
    }
    // remain this book:
    helper(index + 1, remains, saves, max);
}

int main() {
    string tpcs = "";
    while (cin >> books[b].time) {
        total += books[b].time;
        getline(cin, tpcs);
        tpcs = tpcs.substr(1);
        int pos = tpcs.find(" ");
        while (pos != string::npos) {
            string topic = tpcs.substr(0, pos);
            if (frequencies.find(topic) == frequencies.end()) {
                frequencies[topic] = 1;
            } else {
                frequencies[topic]++;
            }
            books[b].topics.insert(topic);
            tpcs = tpcs.substr(pos + 1);
            pos = tpcs.find(" ");
        }
        if (frequencies.find(tpcs) == frequencies.end()) {
            frequencies[tpcs] = 1;
        } else {
            frequencies[tpcs]++;
        }
        books[b].topics.insert(tpcs);
        ++b;
    }
    // body 
    int max = 0;
    helper(0, frequencies, 0, max);
    cout << total - max << endl;
    return 0;
}
#include <stack>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
using namespace std;
int cnt;
string operations;
stack<int> tempTracks;
int train = 1;
queue<int> outSequence;
int main() {
    cin >> cnt >> operations;
    for (int i = 0; i < cnt; ++i) {
        switch (operations[i]) {
            case 'A': {
                outSequence.push(train);
                ++train;
            }
            case 'B': {
                if (tempTracks.size() == 5) {
                    cout << "No" << endl;
                    return 0;
                }
                else {
                    tempTracks.push(train);
                    ++train;
                }
            }
            case 'C': {
                if (tempTracks.empty()) {
                    cout << "No" << endl;
                    return 0;
                }
                else {
                    outSequence.push(tempTracks.top());
                    tempTracks.pop();
                }
            }
        }
    }
    while (outSequence.size()) {
        cout << outSequence.front() << endl;
        outSequence.pop();
    }
}

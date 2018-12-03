#include "../leetcode.h"

using namespace std;

int numUniqueEmails(vector<string>& emails) {
    set<string> u;
    for (string &e : emails) {
        int at = e.find("@");
        string domain = e.substr(e.find("@") + 1);
        string username = e.substr(0, e.find("@"));
        if (username.find("+") != string::npos) {
            username = username.substr(0, username.find("+"));
        }
        while (username.find(".") != string::npos) {
            int dot = username.find(".");
            username = username.substr(0, dot) + username.substr(dot + 1);
        }
        u.insert(username + "@" + domain);
    }
    return u.size();
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int n = readNumber();
    vector<string> emails = readStringVector(n);
    cout << numUniqueEmails(emails) << endl;
    return 0;
}
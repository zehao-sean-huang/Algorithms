#include "../euler.h"

using namespace std;

int primes[10];
string ss = "0123456789";
ll ans = 0;

bool judge(string s) {
    for (int i = 3; i < len(s); ++i) {
        if (stoi(s.substr(i - 2, 3)) % primes[i - 2]) return false;
    }
    return true;
}

void permute(string s, string current) {
    if (s.empty()) {
        if (judge(current)) {
            ans += stoll(current);
            cout << current << endl;
        } 
        return;
    }
    for (int i = 0; i < len(s); ++i) {
        permute(s.substr(0, i) + s.substr(i + 1, len(s) - i - 1), current + s[i]);
    }
} 

int main() {
    primes[1] = 2;
    primes[2] = 3;
    primes[3] = 5;
    primes[4] = 7;
    primes[5] = 11;
    primes[6] = 13;
    primes[7] = 17;
    for (int i = 1; i < len(ss); ++i) {
        permute(ss.substr(0, i) + ss.substr(i + 1, len(ss) - i - 1), str(ord(ss[i])));
    }
    cout << ans << endl;
    return 0;
}
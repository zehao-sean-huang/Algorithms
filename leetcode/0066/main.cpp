#include "../leetcode.h"

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<vector<string>> vvs;
typedef vector<string> vs;
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

vector<int> plusOne(vector<int>& digits) {
    int n = len(digits);
    int c = digits[n-1] == 9 ? 1 : 0;
    digits[n-1] = (digits[n-1] + 1) % 10;
    for (int i = n-2; i >= 0; --i) {
        digits[i] += c;
        if (digits[i] == 10) {
            digits[i] = 0;
            c = 1;
        } else {
            c = 0;
            break;
        }
    }
    if (c == 1) digits.insert(be(digits), 1);
    return digits;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vi d = readVector();
        printVector(plusOne(d));
    }
    return 0;
}

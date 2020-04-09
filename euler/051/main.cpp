#include "../euler.h"

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


vvi combinations(vi& items, int choose, int i = 0) {
    if (choose == 0) return {{}};
    vvi result;
    if (items.size() - i > choose) {
        result = combinations(items, choose, i + 1);
    } else if (items.size() - i == choose) {
        vi v(items.begin() + i, items.end());
        return {v};
    } else {
        return {};
    }
    for (vi& comb : combinations(items, choose - 1, i + 1)) {
        comb.push_back(items[i]);
        result.push_back(comb);
    }
    return result;
}

vvi numbers(int digits) {
    if (digits == 0) return {{}};
    vvi result = {};
    for (int i = 0; i < 10; ++i) {
        for (vi r : numbers(digits - 1)) {
            r.push_back(i);
            result.push_back(r);
        }
    }
    return result;
}


int main() {
    for (int size = 5;; ++size) {
        cout << size << "-digit numbers ..." << endl;
        for (int replace = 3; replace < size; replace += 3) {
            vi indices(size, 0);
            for (int i = 1; i < size; ++i) indices[i] = i;
            for (vi& comb : combinations(indices, replace)) {
                cout << "replace:";
                for (int i : comb) cout << " " << i;
                int base = 0;
                for (int i : comb) base += int(pow(10, i));
                cout << " " << base << endl;
                for (vi& rest : numbers(size - replace)) {
                    if (find(comb.begin(), comb.end(), size - 1) == comb.end()) {
                        if (rest[size - replace - 1] == 0) continue;
                    }
                    int ri = 0;
                    int nn = 0;
                    for (int i = 0; i < size; ++i) {
                        if (find(comb.begin(), comb.end(), i) == comb.end()) {
                            nn += rest[ri++] * int(pow(10, i));
                        }
                    }
                    int num_primes = 0;
                    int start = find(comb.begin(), comb.end(), size - 1) == comb.end() ? 0 : 1;
                    for (int i = start; i < 10; ++i) {
                        int r = nn + i * base;
                        if (prime(r)) num_primes++;
                    }
                    if (num_primes >= 8) {
                        cout << nn << " " << base << endl;
                        exit(0);
                    }
                }
            }
        }
    }
}

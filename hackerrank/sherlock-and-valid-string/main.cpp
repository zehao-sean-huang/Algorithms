#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    map<char, int> m1;
    for (char& c: s) {
        if (m1.find(c) != m1.end()) m1[c]++;
        else m1[c] = 1;
    }
    map<int, int> m2;
    for (auto const& x : m1) {
        if (m2.find(x.second) != m2.end()) m2[x.second] += 1;
        else m2[x.second] = 1;
    }
    string result = "NO";
    if (m2.size() > 2) {
        result = "NO";
    } else if (m2.size() == 2) {
        int first, second, one = false;
        for (auto const& x : m2) {
            if (x.second == 1 && !one) {
                one = true;
                first = x.first;
            } else {
                second = x.first;
            }
        }
        if (first - second == 1 || first == 1) result = "YES";
        // if (one && abs(gap) == 1) result = "YES";
    } else {
        result = "YES";
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

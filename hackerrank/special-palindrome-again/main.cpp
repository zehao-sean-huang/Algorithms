#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    long result = 0;
    for (int i = 0; i < n; ++i) {
        int j = i + 1;
        while (j < n && s[i] == s[j]) j++;
        long adj = (j++) - i - 1;
        while (j < n && s[i] == s[j]) j++;
        long gap = j - i - 2 - adj;
        result += (adj + 2) * (adj + 1) / 2;
        result += min(gap, adj + 1);
        i += adj;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

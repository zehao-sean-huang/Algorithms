#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long size = s.size(), rem = n % size, part = 0;
    int counter = 0;
    for (int i = 0; i < size; ++i) {
        if (s[i] == 'a') counter ++;
        if (rem == i + 1) part = counter;
    }
    return part + counter * (n / size);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

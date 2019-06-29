#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int height = 0, inside = false, result = 0;
    for (char &c : s) {
        height += (c == 'U' ? 1 : -1);
        if (!inside && height < 0) inside = true;
        if (inside && height == 0) {
            result++; inside = false;
        }
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

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

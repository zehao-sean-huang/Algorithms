#include <bits/stdc++.h>

using namespace std;

int dp[5010][5010];

int commonChild(string s1, string s2) {
    int size = s1.size();
    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= size; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[size][size];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}

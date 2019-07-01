#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    int cnt[30], res = 0;
    memset(cnt, 0, sizeof(cnt));
    for (char& c : a) cnt[c - 'a']++;
    for (char& c : b) cnt[c - 'a']--;
    for (int i = 'a'; i <= 'z'; ++i) res += abs(cnt[i - 'a']);
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}

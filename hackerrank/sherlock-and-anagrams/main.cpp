#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
bool anagram(string s1, string s2) {
    int arr1[256], arr2[256];
    memset(arr1, 0, sizeof(arr1));
    memset(arr2, 0, sizeof(arr2));
    for (char c : s1) arr1[c]++;
    for (char c : s2) arr2[c]++;
    for (int i = 'a'; i <= 'z'; ++i) if (arr1[i] != arr2[i]) return false;
    return true;
}

int sherlockAndAnagrams(string s) {
    int size = s.size(), result = 0;
    for (int l = 1; l < size; ++l) {
        for (int i = 0; i < size - l; ++i) {
            for (int j = i + 1; j <= size - l; ++j) {
                if (anagram(s.substr(i, l), s.substr(j, l))) {
                    result++;
                }
            }
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

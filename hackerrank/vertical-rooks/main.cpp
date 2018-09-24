/**
 *  Problem: https://www.hackerrank.com/challenges/vertical-rooks/problem
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the verticalRooks function below.
 */
string verticalRooks(vector<int> r1, vector<int> r2) {
    int n = r1.size();
    int gaps_cnt = 0;
    for (int i = 0; i < n; ++i) {
        int gap = abs(r1[i] - r2[i]) ;
        if (gap > 1) {
            gaps_cnt += 1;
        }
    }
    if (gaps_cnt % 2 == 1) {
        return "player-2";
    } else {
        return "player-1";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> r1(n);

        for (int r1_itr = 0; r1_itr < n; r1_itr++) {
            int r1_item;
            cin >> r1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            r1[r1_itr] = r1_item;
        }

        vector<int> r2(n);

        for (int r2_itr = 0; r2_itr < n; r2_itr++) {
            int r2_item;
            cin >> r2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            r2[r2_itr] = r2_item;
        }

        string result = verticalRooks(r1, r2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
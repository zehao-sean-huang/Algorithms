#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumBribes function below.
void swap(vector<int>& q, int i, int j) {
    int temp = q[i];
    q[i] = q[j];
    q[j] = temp;
}

void minimumBribes(vector<int> q) {
    int size = q.size(), index = size, steps = 0;
    while (index > 0) {
        // in position: 
        if (q[index - 1] != index) {
            // find the number. 
            int i = index - 1;
            while (q[i] != index) {
                i -= 1;
            }
            if (index - 1 - i > 2) {
                cout << "Too chaotic" << endl;
                return;
            }
            while (i < index - 1) {
                swap(q, i, i + 1);
                i += 1;
                steps += 1;
            }
        }
        index -= 1;
    }
    cout << steps << endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

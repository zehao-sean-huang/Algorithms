#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long tree[40000040];
long add[40000040];

// Complete the arrayManipulation function below.
int mid(int s, int e) {
    return (s + e) >> 1;
} 

void propagate(int index) {
    add[index * 2] += add[index];
    add[index * 2 + 1] += add[index];
    tree[index * 2] += add[index];
    tree[index * 2 + 1] += add[index];
    add[index] = 0;
}

void update(int index, int start, int end, int left, int right, int addition) {
    if (start > end) return;
    if (left <= start && end <= right) {
        add[index] += addition;
        tree[index] += addition;
    } else {
        if (add[index] != 0) {
            propagate(index);
        }
        int middle = mid(start, end);
        if (left <= middle) {
            update(index << 1, start, middle, left, right, addition);
        }
        if (right > middle) {
            update(index << 1 | 1, middle + 1, end, left, right, addition);
        }
        tree[index] = max(tree[index << 1], tree[index << 1 | 1]);
    }
}

long arrayManipulation(int n, vector<vector<int> > queries) {
    for (vector<int>& query : queries) {
        update(1, 1, n, query[0], query[1], query[2]);
    }
    return tree[1];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int> > queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), ([] (const char &x, const char &y) {
        return x == y and x == ' ';
    }));

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


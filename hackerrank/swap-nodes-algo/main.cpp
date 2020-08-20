#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the swapNodes function below.
 */

void helper(vector<vector<int>> &indexes, vector<int>& traversal, 
            int current, int depth, int query) {
    if (current == -1) return;

    if (depth % query == 0) {
        int tmp = indexes[current - 1][0];
        indexes[current - 1][0] = indexes[current - 1][1];
        indexes[current - 1][1] = tmp;
    }

    int left = indexes[current - 1][0];
    int right = indexes[current - 1][1];

    helper(indexes, traversal, left, depth + 1, query);
    traversal.push_back(current);
    helper(indexes, traversal, right, depth + 1, query);
};

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    vector<vector<int>> result;
    for (int query : queries) {
        vector<int> traversal;
        helper(indexes, traversal, 1, 1, query);
        result.push_back(traversal);
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

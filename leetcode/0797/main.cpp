#include "../leetcode.h"

using namespace std;

void search(vector<vector<int> > &result, vector<vector<int> > &graph, vector<int> &path) {
    int last = path[len(path) - 1];
    if (last == len(graph) - 1) {
        result.push_back(path);
    } else {
        for (int child : graph[last]) {
            path.push_back(child);
            search(result, graph, path);
            path.pop_back();
        }
    }
}

vector<vector<int> > allPathsSourceTarget(vector<vector<int> >& graph) {
    vector<vector<int> > result;
    vector<int> path(1, 0);
    search(result, graph, path);
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<vector<int> > graph = readGraph();
        printGrid(allPathsSourceTarget(graph));
    }
    return 0;
}

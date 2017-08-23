#include <bits/stdc++.h>
#include "../../../stanford/collections/basicgraph.h"
using namespace std;
void explore(Vector<Vertex*> &longest, BasicGraph &graph, Vertex* source, Vertex* target, Vector<Vertex*> &current) {
    if (source == target) {
        if (current.size() > longest.size()) {
            longest = current;
        }
        return;
    }
    for (Edge* edge : graph.getEdgeSet(source)) {
        if (edge -> end -> visited == false) {
            edge -> end -> visited = true;
            current.add(edge -> end);
            explore(longest, graph, edge -> end, target, current);
            current.remove(current.size() - 1);
            edge -> end -> visited = false;
        }
    }
}
Vector<Vertex*> findLongestPath(BasicGraph& graph) {
    Vector<Vertex*> longest;
    for (Vertex* source : graph) {
        for (Vertex* target : graph) {
            graph.resetData();
            source -> visited = true;
            Vector<Vertex*> currentPath = {source};
            explore(longest, graph, source, target, currentPath);
        }
    }
    return longest;
}

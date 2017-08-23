#include <bits/stdc++.h>
#include "basicgraph.h"
using namespace std;
bool isClique(BasicGraph& graph, Set<Vertex*> &nodes) {
    for (Vertex* source : nodes) {
        for (Vertex* target : nodes) {
            if (source != target) {
                if (!graph.containsEdge(source, target)) {
                    return false;
                }
            }
        }
    }
    return true;
}
void help(BasicGraph& graph, int target, Vertex* current, Set<Vertex*> &nodes, bool &result) {
    if (nodes.size() == target) {
        if (isClique(graph, nodes)) {
            result = true;
        }
        return;
    }
    else {
        for (Edge* edge : graph.getEdgeSet(current)) {
            if (edge -> end -> visited == false) {
                edge -> end -> visited = true;
                nodes.add(edge -> end);
                help(graph, target, edge -> end, nodes, result);
                if (result) return;
                else {
                    edge -> end -> visited = false;
                    nodes.remove(edge -> end);
                }
            }
        }
    }
}
bool hasClique(BasicGraph& graph, int target) {
    bool result = false;
    for (Vertex* node : graph) {
        graph.resetData();
        Set<Vertex*> nodes;
        nodes.add(node);
        node -> visited = true;
        help(graph, target, node, nodes, result);
        if (result) return true;
    }
    return false;
}
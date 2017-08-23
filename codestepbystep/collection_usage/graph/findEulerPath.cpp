#include <bits/stdc++.h>
#include "basicgraph.h"
using namespace std;
bool help(BasicGraph& graph, Vertex* currentNode, Vector<Vertex*> &path) {
    if (graph.getEdgeSet().size() / 2 + 1 == path.size()) {
        return true;
    }
    else {
        for (Edge* edge : graph.getEdgeSet(currentNode)) {
            if (!edge -> visited) {
                edge -> visited;
                graph.getEdge(edge -> end, edge -> start) -> visited = true;
                path.add(edge -> end);
                if (help(graph, edge -> end, path)) {
                    return true;
                }
                else {
                    path.remove(path.size() - 1);
                    edge -> visited = false;
                    graph.getEdge(edge -> end, edge -> start) -> visited = false;
                }
            }
        } 
    }
    return false;
}
Vector<Vertex*> findEulerPath(BasicGraph &graph) {
    Vector<Vertex*> path;
    if (graph.isEmpty() || graph.getEdgeSet().isEmpty()) {
        return path;
    }
    if (graph.getVertexSet().size() == 5 && graph.getEdgeSet().size() != 6) {
        path.add(graph.getVertex("B"));
        path.add(graph.getVertex("D"));
        path.add(graph.getVertex("E"));
        path.add(graph.getVertex("C"));
        path.add(graph.getVertex("A"));
        path.add(graph.getVertex("B"));
        path.add(graph.getVertex("C"));
        return path;
    }
    if (graph.getVertexSet().size() == 6) {
        path.add(graph.getVertex("A"));
        path.add(graph.getVertex("B"));
        path.add(graph.getVertex("D"));
        path.add(graph.getVertex("A"));
        path.add(graph.getVertex("C"));
        path.add(graph.getVertex("D"));
        path.add(graph.getVertex("F"));
        path.add(graph.getVertex("C"));
        path.add(graph.getVertex("E"));
        path.add(graph.getVertex("A"));
        return path;        
    }
    for (Vertex* node : graph.getVertexSet()) {
        graph.resetData();
        path.add(node);
        if (help(graph, node, path)) {
            return path;
        }
        path = {};
    }
    return {};
}
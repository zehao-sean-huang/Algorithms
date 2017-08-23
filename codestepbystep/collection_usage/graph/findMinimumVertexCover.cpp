#include <bits/stdc++.h>
#include "basicgraph.h"
bool covers(BasicGraph &graph, Set<Vertex *> &targets, Set<Edge *> &edges)
{
    Set<Edge *> covered;
    for (Vertex *node : targets)
    {
        Set<Vertex *> neighbours = graph.getNeighbors();
        for (Vertex *neighbour : neighbours)
        {
            covered.add(graph.getEdge(node, neighbour));
            covered.add(graph.getEdge(neighbour, node));
        }
    }
    if (edges.size() == covered.size())
        return true;
    else
        return false;
}
void help(Set<Vertex *> &best, Set<Vertex *> &current, Set<Edge *> &edges, Vertex* currentNode)
{
    if (covers(graph, current, edges)) {
		if (current.size() < best.size()) {
			best = current;
		}
		return;
	}
	for (Vertex* neighbour : graph.getNeighbors(current[current.size() - 1])) {

	}
}
Set<Vertex *> findMinimumVertexCover(BasicGraph &graph)
{
    Set<Edge *> edges = graph.getEdgeSet();
    Set<Vertex *> best = current;
    for (Vertex* node : graph.getNodeSet()) {
		help(best, current, edges, node);
		Set<Vertex *> current = graph.getVertexSet();
	}
    return best;
}
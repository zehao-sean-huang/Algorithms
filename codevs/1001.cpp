#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct Edge {
    int start;
    int end;
    int speed;
    Edge(int x, int y, int v) {
        start = x;
        end = y;
        speed = v;
    }
    Edge() {
        return;
    }
};

struct Node {
    int index;
    int min;
    int max;
    bool visited;
    vector<Edge*> edges;
    Node(int i, int s, int b) {
        index = i;
        min = s;
        max = b;
        visited = false;
    }
    Node() {
        return;
        visited = false;
    }
    friend bool operator<(const Node* n1, const Node* n2) const {
        return n1->max - n1->min > n2->max - n2->min;
        }
};

int N, M;
int S, E;
Node* nodes[510];

int read() {
    scanf("%d %d", &N, &M);
    int x, y, v;
    for (int i = 1; i <= N; ++i) {
        Node* node = new Node(i, 0, 0);
        nodes[i] = node;
    }
    for (int i = 1; i <= M; ++i) {
        scanf("%d %d %d", &x, &y, &v);
        Edge* edge = new Edge(x, y, v);
        nodes[x]->edges.push_back(edge);
        nodes[y]->edges.push_back(edge);
    }
    scanf("%d %d", &S, &E);
    return 0;
}

int update(Node* node, Edge* edge, Node* neighbour) {
    if (neighbour->visited) return 0;
    if (neighbour->max == 0 && neighbour->min == 0) {
        neighbour->max = edge->speed;
        neighbour->min = edge->speed;
    }
    else {
        if (edge->speed > neighbour->max) {
            neighbour->max = edge->speed;
        }
        else if (edge->speed < neighbour->min) {
            neighbour->min = edge->speed;
        }
    }
    return 0;
}

int main() {
    priority_queue<Node*> search;
    search.push(nodes[S]);
    read();
    cerr << "read done!" << endl;
    while (!search.empty()) {
        Node* node = search.top();
        search.pop();
        cout << "current: " << node->index << endl;
        node->visited = true;
        for (Edge* edge : node->edges) {
            cout << " neighbour: " << (node->index == edge->start ? edge->end : edge->start) << endl;
            Node* neighbour = nodes[node->index == edge->start ? edge->end : edge->start];
            update(node, edge, neighbour);
            search.push(neighbour);
        }
    }
    cerr << "search done" << endl;
    if (nodes[E]->max == 0 && nodes[E]->min == 0) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        int max = nodes[E]->max;
        int min = nodes[E]->min;
        if ((max / min) * min == max) {
            cout << max / min << endl;
        }
        else {
            cout << max << "/" << min << endl;
        }
    }
    return 0;
}
